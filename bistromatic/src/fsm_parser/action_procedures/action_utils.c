/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:16:13 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 14:17:29 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"

void		bsm_set_op_type(char op_token, t_operator *operator,
				t_state current_state)
{
	if (op_token == '(')
		operator->op_type = OPEN_BRK;
	else if (op_token == ')')
		operator->op_type = CLOSE_BRK;
	else if (op_token == '*')
		operator->op_type = MUL;
	else if (op_token == '/')
		operator->op_type = DIV;
	else if (op_token == '%')
		operator->op_type = MOD;
	else if (op_token == '+')
		operator->op_type = ADD;
	else if (op_token == '-')
	{
		if (current_state == STATE_ReadOperand ||
				current_state == STATE_ReadCloseBracket)
			operator->op_type = SUB;
		else
			operator->op_type = MSIGN;
	}
	else
		bsm_putstr("syntax error", 2);
}

void		bsm_set_op_precedence(t_operator *operator)
{
	if (operator->op_type == OPEN_BRK ||
		operator->op_type == CLOSE_BRK)
		operator->precedence = 4;
	else if (operator->op_type == MSIGN)
		operator->precedence = 3;
	else if (operator->op_type == MUL ||
		operator->op_type == DIV ||
		operator->op_type == MOD)
		operator->precedence = 2;
	else
		operator->precedence = 1;
}

void		bsm_enqueue_operator(t_operator *stack_top_operator,
				char *rpn_arith_expr, t_position *pos)
{
	if (!stack_top_operator)
		return ;
	if (stack_top_operator->op_type == OPEN_BRK)
		(rpn_arith_expr[pos->rpn_pos] = '(');
	else if (stack_top_operator->op_type == MUL)
		(rpn_arith_expr[pos->rpn_pos] = '*');
	else if (stack_top_operator->op_type == DIV)
		(rpn_arith_expr[pos->rpn_pos] = '/');
	else if (stack_top_operator->op_type == MOD)
		(rpn_arith_expr[pos->rpn_pos] = '%');
	else if (stack_top_operator->op_type == ADD)
		(rpn_arith_expr[pos->rpn_pos] = '+');
	else if (stack_top_operator->op_type == SUB)
		(rpn_arith_expr[pos->rpn_pos] = '-');
	else if (stack_top_operator->op_type == MSIGN)
		(rpn_arith_expr[pos->rpn_pos] = '#');
}

void		bsm_enqueue_operand_digit(t_fsm *fsm, int c)
{
	(fsm->rpn_arith_expr)[fsm->pos->rpn_pos] = (char)c;
	fsm->pos->rpn_pos++;
}

t_operator	*bsm_new_operator(char op_token, t_fsm *fsm)
{
	t_operator *new_operator;

	if (!(new_operator = malloc(sizeof(t_operator))))
	{
		bsm_putstr("syntax error", 2);
		return (NULL);
	}
	bsm_set_op_type(op_token, new_operator, fsm->current_state);
	bsm_set_op_precedence(new_operator);
	return (new_operator);
}
