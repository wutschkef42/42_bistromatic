/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neg_str_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 20:26:04 by dpearson          #+#    #+#             */
/*   Updated: 2018/01/14 20:26:04 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm_tools.h"

char	*remove_neg(char *str)
{
	char	*tmp;
	int		len;

	len = bsm_strlen(str);
	tmp = malloc(len);
	tmp[len - 1] = '\0';
	len--;
	while (len--)
		tmp[len] = str[len + 1];
	free(str);
	return (tmp);
}

char	*add_neg(char *str)
{
	char	*tmp;
	int		len;
	int		i;

	len = bsm_strlen(str);
	tmp = malloc(len + 2);
	tmp[len + 1] = '\0';
	tmp[0] = '-';
	i = 0;
	while (i < len)
	{
		tmp[i + 1] = str[i];
		i++;
	}
	free(str);
	return (tmp);
}