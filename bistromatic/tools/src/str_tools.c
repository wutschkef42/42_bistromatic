/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:57:36 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:58:12 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm_tools.h"

int		bsm_strequ(char *s1, char *s2)
{
	if (s1 && s2)
	{
		while (*s1 || *s2)
		{
			if (*s1 != *s2)
				return (0);
			s2++;
			s1++;
		}
	}
	return (1);
}

size_t	bsm_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

char	*bsm_strncpy(char *dst, const char *src, size_t n)
{
	int		i;
	size_t	size;

	size = n;
	if (!src || !dst)
		return (NULL);
	i = 0;
	while (src[i] && n--)
	{
		dst[i] = src[i];
		i++;
	}
	dst[size] = '\0';
	return ((char*)dst);
}

void	bsm_putstr(const char *s, int fd)
{
	if (!s)
		return ;
	write(1, s, bsm_strlen(s));
	write(1, "\n", 1);
}

char	*bsm_strchr(const char *s, char c)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return ((char*)&s[i]);
	}
	return (NULL);
}
