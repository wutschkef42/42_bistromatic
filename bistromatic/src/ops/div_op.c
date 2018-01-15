/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:29:43 by dpearson          #+#    #+#             */
/*   Updated: 2018/01/10 20:54:43 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "bsm_tools.h"

char	*add_zeroes(char *str, int len, const char *charset)
{
	char	*tmp;
	int		i;

	tmp = bsm_memalloc(len + 1);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	while (i < len)
	{
		tmp[i] = charset[0];
		i++;
	}
	return (tmp);
}

int		zero_check(char *dividend, char *divisor, const char *charset)
{
	int		z;
	int		init_len;
	char	*tmp;

	tmp = divisor;
	init_len = bsm_strlen(divisor);
	z = 1;
	while (is_bigger(dividend, tmp, charset))
	{
		if (tmp != divisor)
			free(tmp);
		tmp = add_zeroes(divisor, z + init_len, charset);
		z++;
	}
	z--;
	if (is_bigger(tmp, dividend, charset))
		z--;
	free(tmp);
	return (((z) > 0) ? z : 0);
}

char	*bsm_div(t_ops *ops)
{
	char	*tmp_divisor;
	char	*ret;
	int		zero;

	ops->j = 0;
	while (is_bigger(ops->mod, ops->str2, ops->charset))
	{
		zero = zero_check(ops->mod, ops->str2, ops->charset);
		tmp_divisor = add_zeroes(ops->str2, ops->len2 + zero, ops->charset);
		ops->i = 0;
		while ((is_bigger(ops->mod, tmp_divisor, ops->charset) ||
			(bsm_strequ(ops->mod, tmp_divisor))) && ++ops->i)
			ops->mod = dispatch(ops->mod, tmp_divisor, '-', ops->charset);
		ops->result[ops->j++] = ops->i;
	}
	while (zero--)
		ops->result[ops->j++] = 0;
	ret = bsm_memalloc(ops->j + 1);
	while (ops->j)
	{
		ret[ops->j - 1] = ops->charset[ops->result[ops->j - 1]];
		ops->j--;
	}
	free(ops->result);
	return (((ops->neg) ? add_neg(ret) : ret));
}

static int	div_zero_check(t_ops *ops)
{
	int i;

	i = 0;
	while (ops->str2[i])
	{
		if (ops->str2[i] != ops->charset[0])
			return (0);
		i++;
	}
	return (1);
}

char	*op_div(t_ops *ops)
{
	char	*quotient;

	if (div_zero_check(ops) || !(negative_handle(ops)))
		return(NULL);
	if (bsm_strequ(ops->str1, ops->str2))
	{
		quotient = bsm_memalloc(2 + ops->neg);
		if (ops->neg)
			quotient[0] = '-';
		quotient[0 + ops->neg] = ops->charset[1];
		return (quotient);
	}
	else if (is_bigger(ops->str2, ops->str1, ops->charset))
	{
		quotient = bsm_memalloc(2);
		quotient[0] = ops->charset[0];
		return (quotient);
	}
	ops->result = bsm_memalloc((sizeof(int)) * (ops->len1 + 1));
	ops->mod = bsm_strnew(ops->len1 + 1);
	ops->mod = bsm_strncpy(ops->mod, ops->str1, ops->len1);
	quotient = bsm_div(ops);
	if (!ops->mod_tag)
		free(ops->mod);
	return (quotient);
}
