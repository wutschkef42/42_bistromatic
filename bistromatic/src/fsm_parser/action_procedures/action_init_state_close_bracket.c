/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_init_state_close_bracket.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:54:23 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 13:54:25 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_init_state_close_bracket(t_fsm *fsm, int c)
{
	(void)c;
	fsm->current_state = STATE_ParseError;
}
