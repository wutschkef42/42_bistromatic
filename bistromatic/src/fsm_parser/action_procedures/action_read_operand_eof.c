/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_operand_eof.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:04:05 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 14:04:06 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_operand_eof(t_fsm *fsm, int c)
{
	(void)c;
	(fsm->rpn_arith_expr)[fsm->pos->rpn_pos] = TOKEN_DELIM;
	fsm->pos->rpn_pos++;
	fsm->current_state = STATE_EndOfData;
}
