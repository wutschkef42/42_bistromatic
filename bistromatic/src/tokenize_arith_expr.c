/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_arith_expr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:48:11 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:49:16 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"
#include "stack.h"

static int	bsm_count_words(const char *s)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == TOKEN_DELIM)
			i++;
		if (s[i] && !(s[i] == TOKEN_DELIM))
			count++;
		while (s[i] && !(s[i] == TOKEN_DELIM))
			i++;
	}
	return (count);
}

static int	bsm_word_len(const char *s)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (s[i] == 0)
		i++;
	while (!(s[i] == 0))
	{
		len++;
		i++;
	}
	return (len);
}

char		**bsm_tokenize(const char *s)
{
	int		i;
	int		j;
	int		k;
	char	**s2;

	if (!s || !(s2 = (char**)malloc(sizeof(*s2) * bsm_count_words(s) + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < bsm_count_words(s))
	{
		k = 0;
		if (!(s2[i] = bsm_strnew(bsm_word_len(&s[j]) + 1)))
			s2[i] = NULL;
		while (s[j] == TOKEN_DELIM)
			j++;
		while (!(s[j] == TOKEN_DELIM) && s[j])
			s2[i][k++] = s[j++];
		s2[i][k] = '\0';
	}
	s2[i] = 0;
	return (s2);
}
