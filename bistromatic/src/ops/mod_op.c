/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:30:07 by dpearson          #+#    #+#             */
/*   Updated: 2018/01/15 13:48:06 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "bsm_tools.h"

char	*op_mod(t_ops *ops)
{
	char	*tmp;

	ops->mod_tag = 1;
	if (!is_bigger(ops->str1, ops->str2, ops->charset))
		return (ops->str1);
	tmp = op_div(ops);
	free(tmp);
	return ((ops->neg) ? add_neg(ops->mod) : ops->mod);
}
