/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:29:39 by dpearson          #+#    #+#             */
/*   Updated: 2018/01/10 20:54:29 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "bsm_tools.h"

void	bsm_mul(t_ops *ops)
{
	while (ops->i >= 0)
	{
		ops->carry = 0;
		ops->num1 = index_char(ops->str1[ops->i], ops->charset);
		ops->i_str2 = 0;
		ops->j = ops->len2 - 1;
		while (ops->j >= 0)
		{
			ops->num2 = index_char(ops->str2[ops->j], ops->charset);
			ops->sum = ops->num1 * ops->num2 +
						ops->result[ops->i_str1 + ops->i_str2] + ops->carry;
			ops->carry = ops->sum / ops->base;
			ops->result[ops->i_str1 + ops->i_str2] = ops->sum % ops->base;
			ops->i_str2++;
			ops->j--;
		}
		if (ops->carry > 0)
			ops->result[ops->i_str1 + ops->i_str2] += ops->carry;
		ops->i--;
		ops->i_str1++;
	}
	ops->res_len = (ops->len1 + ops->len2 - 1);
	while (ops->res_len >= 0 && !ops->result[ops->res_len])
		ops->res_len--;
	ops->res_len++;
}

char	*op_mul(t_ops *ops)
{
	char	*res;

	negative_handle(ops);
	ops->result = bsm_memalloc(sizeof(int) * (ops->len1 + ops->len2));
	ops->i = ops->len1 - 1;
	ops->j = ops->len2 - 1;
	bsm_mul(ops);
	res = bsm_intarr_to_str(ops->result, ops->res_len, 1, ops->charset);
	free(ops->result);
	return (ops->neg ? (add_neg(res)) : res);
}
