/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:26:01 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:34:48 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"

/*
 * translate <space> char to -32
 * translate escape sequences \x to x ??? maybe not necessary
*/

char	*bsm_normalize_charset(const char *charset_in)
{
	char	*charset_out;
	int		len;

	len = bsm_strlen(charset_in);
	if (!(charset_out = malloc(sizeof(char) * len + 1)))
		return (NULL);
}
