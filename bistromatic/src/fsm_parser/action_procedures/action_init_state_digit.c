/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_init_state_digit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:54:58 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 13:54:59 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_init_state_digit(t_fsm *fsm, int c)
{
	(void)c;
	fsm->current_state = STATE_ReadOperand;
	bsm_enqueue_operand_digit(fsm, c);
}
