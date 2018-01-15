/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_sign_digit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:11:19 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 14:11:24 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_sign_digit(t_fsm *fsm, int c)
{
	bsm_enqueue_operand_digit(fsm, c);
	fsm->current_state = STATE_ReadOperand;
}
