/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:30:17 by dpearson          #+#    #+#             */
/*   Updated: 2018/01/10 20:54:36 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "bsm_tools.h"
#include <stdio.h>

/*
**	Used to swap str1 and str2 in cases where str2 is larger. Due to this,
**	negativity is always flagged and the output of bsm_sub will be pos.
*/

void		big_swap(t_ops *ops)
{
	char	*tmp;
	int		len_tmp;

	if (!is_bigger(ops->str1, ops->str2, ops->charset))
	{
		ops->neg = 1;
		tmp = ops->str1;
		len_tmp = ops->len1;
		ops->str1 = ops->str2;
		ops->len1 = ops->len2;
		ops->len2 = len_tmp;
		ops->str2 = tmp;
	}
}

static void	bsm_sub(t_ops *ops)
{
	int		k;

	k = ops->max_len - 1;
	big_swap(ops);
	while (k >= 0)
	{
		ops->num1 = ((ops->len1 - ops->max_len + k) >= 0) ?
		index_char(ops->str1[k - ops->max_len + ops->len1], ops->charset) : 0;
		ops->num2 = ((ops->len2 - ops->max_len + k) >= 0) ?
		index_char(ops->str2[k - ops->max_len + ops->len2], ops->charset) : 0;
		ops->sum = ops->num1 - ops->num2 - ops->carry;
		if (ops->sum < 0)
		{
			ops->carry = 1;
			ops->sum += ops->base;
		}
		else
			ops->carry = 0;
		ops->result[k + 1] = ops->sum;
		k--;
	}
}

static char	*sub_handle_negatives(t_ops *ops)
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
			tmp = ops->str1;
			ops->str1 = ops->str2;
			ops->str2 = tmp;
			return (op_sub(ops));
		}
		else
			return (add_neg(op_add(ops)));
	}
	ops->str2 = remove_neg(ops->str2);
	ops->len2--;
	return (op_add(ops));
}

char		*op_sub(t_ops *ops)
{
	char	*res;

	if (ops->str1[0] == '-' || ops->str2[0] == '-')
		return (sub_handle_negatives(ops));
	ops->len1 = bsm_strlen(ops->str1);
	ops->len2 = bsm_strlen(ops->str2);
	ops->max_len = MAX(ops->len1, ops->len2);
	ops->res_len = ops->max_len + 1;
	if (bsm_strequ(ops->str1, ops->str2))
	{
		res = bsm_memalloc(2);
		res[0] = ops->charset[0];
		return (res);
	}
	ops->result = bsm_memalloc(sizeof(int) * (ops->max_len + 2));
	bsm_sub(ops);
	res = bsm_subarr_to_str(ops->result, ops->res_len, ops->charset);
	free(ops->result);
	return (ops->neg ? add_neg(res) : res);
}
