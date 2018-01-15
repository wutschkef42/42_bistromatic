/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:56:45 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:57:12 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm_tools.h"

static int	bsm_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/*
** converts a base10 string number to base10 integer
** !!! returns 0 on error
*/

int			bsm_atoi(const char *addr)
{
	int	result;

	if (!addr)
		return (0);
	result = 0;
	while (*addr)
	{
		if (!(bsm_isdigit(*addr)))
			return (0);
		result = result * 10 + *addr - '0';
		addr++;
	}
	return (result);
}
