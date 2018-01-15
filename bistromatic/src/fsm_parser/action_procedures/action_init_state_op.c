/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_init_state_op.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:55:48 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 13:55:51 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_init_state_op(t_fsm *fsm, int c)
{
	(void)c;
	fsm->current_state = STATE_ParseError;
}
