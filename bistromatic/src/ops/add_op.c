/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:29:47 by dpearson          #+#    #+#             */
/*   Updated: 2018/01/10 20:17:34 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "bsm_tools.h"

static void	bsm_add(t_ops *ops)
{
	int		k;

	k = ops->max_len - 1;
	while (k >= 0)
	{
		ops->num1 = ((ops->len1 - ops->max_len + k) >= 0) ?
		index_char(ops->str1[k - ops->max_len + ops->len1], ops->charset) : 0;
		ops->num2 = ((ops->len2 - ops->max_len + k) >= 0) ?
		index_char(ops->str2[k - ops->max_len + ops->len2], ops->charset) : 0;
		ops->sum = ops->num1 + ops->num2 + ops->carry;
		if (ops->sum > (ops->base - 1))
		{
			ops->carry = 1;
			ops->sum -= ops->base;
		}
		else
			ops->carry = 0;
		ops->result[k + 1] = ops->sum;
		k--;
	}
	if (ops->carry)
		ops->result[k + 1] = 1;
}

static char	*handle_negatives(t_ops *ops)
{
	char	*tmp;

	if (ops->str1[0] == '-')
	{
		ops->str1 = remove_neg(ops->str1);
		ops->len1--;
		if (ops->str2[0] == '-')
		{
			ops->str2 = remove_neg(ops->str2);
			ops->len2--;
			return (add_neg(op_add(ops)));
		}
		else
		{
			tmp = ops->str1;
			ops->str1 = ops->str2;
			ops->str2 = tmp;
			return (op_sub(ops));
		}
	}
	ops->str2 = remove_neg(ops->str2);
	ops->len2--;
	return (op_sub(ops));
}

char		*op_add(t_ops *ops)
{
	char	*res;

	ops->len1 = bsm_strlen(ops->str1);
	ops->len2 = bsm_strlen(ops->str2);
	if (ops->str1[0] == '-' || ops->str2[0] == '-')
		return (handle_negatives(ops));
	ops->max_len = MAX(ops->len1, ops->len2);
	ops->res_len = ops->max_len + 1;
	ops->result = bsm_memalloc(sizeof(int) * (ops->max_len + 2));
	bsm_add(ops);
	res = bsm_intarr_to_str(ops->result, ops->res_len, 0, ops->charset);
	free(ops->result);
	return (res);
}
