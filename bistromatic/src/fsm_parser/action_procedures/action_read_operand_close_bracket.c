/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_operand_close_bracket.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:03:31 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 14:03:35 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

/*
** pop operators off operator stack until first '('
** enqueue popped operators to output string
*/

void	action_read_operand_close_bracket(t_fsm *fsm, int c)
{
	(fsm->rpn_arith_expr)[fsm->pos->rpn_pos] = TOKEN_DELIM;
	fsm->pos->rpn_pos++;
	pop_til_open_bracket(fsm, c);
	fsm->current_state = STATE_ReadCloseBracket;
}
