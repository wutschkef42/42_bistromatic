/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arith_expr2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:34:03 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 15:34:31 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"

/*
** check if base charset contains invalid chars (operators or brackets)
*/

int		charset_invalid(const char *charset)
{
	size_t		i;
	static char	forbidden[7] = {'+', '-', '*', '/', '%', '(', ')'};

	if (!charset)
		return (1);
	i = 0;
	while (i < sizeof(forbidden) / sizeof(forbidden[0]))
	{
		if (bsm_strchr(charset, forbidden[i]))
		{
			bsm_putstr("syntax error", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
