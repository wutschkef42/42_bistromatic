/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_operator_digit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:06:51 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 14:06:54 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_operator_digit(t_fsm *fsm, int c)
{
	bsm_enqueue_operand_digit(fsm, c);
	fsm->current_state = STATE_ReadOperand;
}
