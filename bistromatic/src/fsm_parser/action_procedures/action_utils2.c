/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:18:20 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 15:18:09 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"

void	preprocess_stack(t_fsm *fsm, t_operator *new_operator)
{
	t_operator	*stack_top_operator;

	stack_top_operator = (t_operator*)bsm_stack_peek(fsm->operators);
	while (stack_top_operator && stack_top_operator->op_type != OPEN_BRK &&
			stack_top_operator->precedence >= new_operator->precedence)
	{
		if (stack_top_operator->op_type == MSIGN &&
				new_operator->op_type == MSIGN)
			break ;
		stack_top_operator = (t_operator*)bsm_stack_pop(&(fsm->operators));
		if (stack_top_operator)
		{
			bsm_enqueue_operator(stack_top_operator, fsm->rpn_arith_expr,
				fsm->pos);
			fsm->pos->rpn_pos++;
			(fsm->rpn_arith_expr)[fsm->pos->rpn_pos] = TOKEN_DELIM;
		}
		stack_top_operator = (t_operator*)bsm_stack_peek(fsm->operators);
		fsm->pos->rpn_pos++;
	}
}

/*
** pop operators off operator stack until first '('
** enqueue popped operators to output string
*/

void	pop_til_open_bracket(t_fsm *fsm, int c)
{
	t_operator	*stack_top_operator;

	(void)c;
	stack_top_operator = (t_operator*)bsm_stack_peek(fsm->operators);
	while (stack_top_operator && stack_top_operator->op_type != OPEN_BRK)
	{
		stack_top_operator = (t_operator*)bsm_stack_pop(&(fsm->operators));
		free(stack_top_operator);
		bsm_enqueue_operator(stack_top_operator, fsm->rpn_arith_expr, fsm->pos);
		stack_top_operator = (t_operator*)bsm_stack_peek(fsm->operators);
		fsm->pos->rpn_pos++;
		(fsm->rpn_arith_expr)[fsm->pos->rpn_pos] = TOKEN_DELIM;
		fsm->pos->rpn_pos++;
		(fsm->rpn_arith_expr)[fsm->pos->rpn_pos] = TOKEN_DELIM;
	}
	if (stack_top_operator)
	{
		if (stack_top_operator->op_type == OPEN_BRK)
			bsm_stack_pop(&(fsm->operators));
		else
			fsm->current_state = STATE_ParseError;
		return ;
	}
	else
		fsm->current_state = STATE_ParseError;
}

void	insert_new_operator(t_fsm *fsm, t_operator *new_operator)
{
	t_operator	*stack_top_operator;

	if (!(fsm->operators))
	{
		bsm_stack_push(&(fsm->operators), bsm_stack_new((void*)new_operator,
			sizeof(t_operator)));
		return ;
	}
	stack_top_operator = (t_operator*)bsm_stack_peek(fsm->operators);
	preprocess_stack(fsm, new_operator);
	bsm_stack_push(&(fsm->operators), bsm_stack_new((void*)new_operator,
		sizeof(t_operator)));
}
