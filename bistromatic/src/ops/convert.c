/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:23:46 by dpearson          #+#    #+#             */
/*   Updated: 2018/01/10 20:16:22 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "bsm_tools.h"
#include <stdio.h>

int		index_char(char c, const char *charset)
{
	return (bsm_strchr(charset, c) - charset);
}

char	*bsm_intarr_to_str(int *result, int len, int rev, const char *charset)
{
	char	*str;
	int		i;
	int		j;

	if (len <= 0)
	{
		str = bsm_memalloc(2);
		str[0] = charset[0];
		return (str);
	}
	str = bsm_strnew(len + 1);
	str[len] = '\0';
	j = 0;
	if (!rev)
		while (!result[j])
			j++;
	i = 0;
	while (i < (len - j))
	{
		str[i] = charset[(rev) ? result[len - i - 1] : result[i + j]];
		i++;
	}
	return (str);
}

char	*bsm_subarr_to_str(int *result, int len, const char *charset)
{
	char	*str;
	int		i;
	int		j;

	if (len <= 0)
	{
		str = bsm_memalloc(2);
		str[0] = charset[0];
		return (str);
	}
	str = bsm_strnew(len + 1);
	j = 0;
	while (!result[j])
		j++;
	if (j)
		len++;
	i = 0;
	while (i < (len - ((j) ? (j + 1) : 0)))
	{
		str[i] = charset[result[i + j]];
		i++;
	}
	return (str);
}
