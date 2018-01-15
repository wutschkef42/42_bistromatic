/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:57:30 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:58:50 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm_tools.h"
#include <stdlib.h>

void	*bsm_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	size_t	size;

	size = n;
	if (!src || !dst)
		return (NULL);
	i = 0;
	while (n--)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	((char*)dst)[size] = 0;
	return ((void*)dst);
}

void	bsm_bzero(void *ptr, size_t size)
{
	char	*tmp;

	tmp = (char *)ptr;
	while (size--)
		*(tmp++) = 0;
}

void	*bsm_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	bsm_bzero(mem, size);
	return (mem);
}

char	*bsm_strnew(size_t size)
{
	char *str;

	str = malloc(sizeof(char) * size);
	bsm_bzero(str, size);
	return (str);
}
