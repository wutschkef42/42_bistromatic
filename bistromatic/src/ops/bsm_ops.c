/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsm_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:06:23 by dpearson          #+#    #+#             */
/*   Updated: 2018/01/10 20:14:50 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "bsm_tools.h"

const char	g_ops[6] = "+-/*%";

char	*(*g_op_funcs[])(t_ops *) = {op_add, op_sub, op_div, op_mul, op_mod};

int		negative_handle(t_ops *ops)
{
	if (ops->str1[0] == '-')
	{
		ops->str1 = remove_neg(ops->str1);
		ops->len1--;
		ops->neg = 1;
	}
	if (ops->str2[0] == '-')
	{
		ops->str2 = remove_neg(ops->str2);
		ops->len2--;
		ops->neg = ((ops->neg) ? 0 : 1);
	}
	return (1);
}

int		is_bigger(char *big, char *small, const char *charset)
{
	int		b_len;
	int		s_len;
	int		i;

	b_len = bsm_strlen(big);
	s_len = bsm_strlen(small);
	if (b_len == s_len)
	{
		i = 0;
		while (i < b_len)
		{
			if (index_char(big[i], charset) < index_char(small[i], charset))
				return (0);
			if (index_char(big[i], charset) > index_char(small[i], charset))
				return (1);
			i++;
		}
	}
	return (b_len > s_len);
}

char	*dispatch(char *str1, char *str2, char op, const char *charset)
{
	int		i;
	t_ops	*ops;
	char	*ret;

	i = 0;
	ops = bsm_memalloc(sizeof(t_ops));
	ops->len1 = bsm_strlen(str1);
	ops->len2 = bsm_strlen(str2);
	ops->mod_tag = 0;
	ops->str1 = str1;
	ops->str2 = str2;
	ops->neg = 0;
	ops->charset = charset;
	ops->base = bsm_strlen(charset);
	while (g_ops[i])
	{
		if (g_ops[i] == op)
		{
			ret = g_op_funcs[i](ops);
			free(ops);
			return (ret);
		}
		i++;
	}
	return (NULL);
}
