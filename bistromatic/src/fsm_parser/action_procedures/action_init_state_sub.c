/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_init_state_sub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:56:45 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 13:57:03 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_init_state_sub(t_fsm *fsm, int c)
{
	t_operator	*new_operator;

	fsm->current_state = STATE_ReadSign;
	new_operator = bsm_new_operator((char)c, fsm);
	insert_new_operator(fsm, new_operator);
}
