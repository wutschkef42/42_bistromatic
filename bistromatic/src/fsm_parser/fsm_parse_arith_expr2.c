/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_parse_arith_expr2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:28:02 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 15:28:21 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"
#include "stack.h"

char		*strip_whitespace(char *s)
{
	int len;

	len = bsm_strlen(s);
	while (s[len - 1] == TOKEN_DELIM)
	{
		s[len - 1] = '\0';
		len--;
	}
	return (s);
}
