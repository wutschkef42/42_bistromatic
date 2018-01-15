/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:37:38 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:37:44 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "bsm_tools.h"
#include <stdio.h>

int			bsm_is_operator(char c)
{
	size_t		i;
	static char	ops[8] = {'+', '-', '*', '/', '%', '(', ')', '#'};

	i = 0;
	while (i < sizeof(ops) / sizeof(ops[0]))
	{
		if (c == ops[i])
			return (1);
		i++;
	}
	return (0);
}
