/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_sign_sub.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:13:06 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 14:13:08 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_sign_sub(t_fsm *fsm, int c)
{
	t_operator	*new_operator;

	new_operator = bsm_new_operator((char)c, fsm);
	insert_new_operator(fsm, new_operator);
	fsm->current_state = STATE_ReadSign;
}
