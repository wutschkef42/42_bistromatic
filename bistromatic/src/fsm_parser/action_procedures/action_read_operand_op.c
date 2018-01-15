/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_operand_op.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:04:24 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 14:04:37 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_operand_op(t_fsm *fsm, int c)
{
	t_operator	*new_operator;

	new_operator = bsm_new_operator((char)c, fsm);
	(fsm->rpn_arith_expr)[fsm->pos->rpn_pos] = TOKEN_DELIM;
	fsm->pos->rpn_pos++;
	insert_new_operator(fsm, new_operator);
	fsm->current_state = STATE_ReadOperator;
}
