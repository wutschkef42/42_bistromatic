/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_init_state_add.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:53:56 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 13:53:58 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_init_state_add(t_fsm *fsm, int c)
{
	(void)c;
	fsm->current_state = STATE_ReadSign;
}
