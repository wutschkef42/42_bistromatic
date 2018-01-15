/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_parse_arith_expr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:22:14 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 15:29:00 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"
#include "stack.h"

void		(*const g_state_table[MAX_STATES][MAX_EVENTS])(t_fsm *fsm, int c) =
{
	{
		action_end_of_data,
		action_end_of_data,
		action_end_of_data,
		action_end_of_data,
		action_end_of_data,
		action_end_of_data,
		action_end_of_data
	},
	{
		action_init_state_add,
		action_init_state_close_bracket,
		action_init_state_digit,
		action_init_state_eof,
		action_init_state_op,
		action_init_state_open_bracket,
		action_init_state_sub
	},
	{
		action_parse_error,
		action_parse_error,
		action_parse_error,
		action_parse_error,
		action_parse_error,
		action_parse_error,
		action_parse_error
	},
	{
		action_read_close_bracket_op,
		action_read_close_bracket_close_bracket,
		action_read_close_bracket_digit,
		action_read_close_bracket_eof,
		action_read_close_bracket_op,
		action_read_close_bracket_open_bracket,
		action_read_close_bracket_op
	},
	{
		action_read_open_bracket_add,
		action_read_open_bracket_close_bracket,
		action_read_open_bracket_digit,
		action_read_open_bracket_eof,
		action_read_open_bracket_op,
		action_read_open_bracket_open_bracket,
		action_read_open_bracket_sub
	},
	{
		action_read_operand_op,
		action_read_operand_close_bracket,
		action_read_operand_digit,
		action_read_operand_eof,
		action_read_operand_op,
		action_read_operand_open_bracket,
		action_read_operand_op
	},
	{
		action_read_operator_add,
		action_read_operator_close_bracket,
		action_read_operator_digit,
		action_read_operator_eof,
		action_read_operator_op,
		action_read_operator_open_bracket,
		action_read_operator_sub
	},
	{
		action_read_sign_add,
		action_read_sign_close_bracket,
		action_read_sign_digit,
		action_read_sign_eof,
		action_read_sign_op,
		action_read_sign_open_bracket,
		action_read_sign_sub
	}
};

static int	bsm_init_state_machine(t_fsm **fsm, int expr_len, t_position *pos)
{
	if (!((*fsm) = (t_fsm*)malloc(sizeof(t_fsm))) ||
		!((*fsm)->rpn_arith_expr = (char*)malloc(sizeof(char) *
			expr_len * 2 + 10)))
	{
		bsm_putstr("syntax error", 2);
		return (0);
	}
	(*fsm)->operators = NULL;
	(*fsm)->current_state = STATE_InitState;
	(*fsm)->pos = pos;
	return (1);
}

static int	bsm_get_next_char(const char *infix_arith_expr, t_position *pos)
{
	int c;

	if (!infix_arith_expr[pos->infix_pos])
		return (-1);
	c = (int)infix_arith_expr[pos->infix_pos];
	(pos->infix_pos)++;
	return (c);
}

static void	bsm_pop_operator_stack(t_fsm *fsm, char *rpn_arith_expr,
				t_position *pos, t_stack **operators)
{
	t_operator	*stack_top_operator;

	stack_top_operator = (t_operator*)bsm_stack_peek(*operators);
	while (stack_top_operator)
	{
		stack_top_operator = (t_operator*)bsm_stack_pop(operators);
		if (stack_top_operator->op_type == OPEN_BRK)
		{
			fsm->current_state = STATE_ParseError;
			return ;
		}
		bsm_enqueue_operator(stack_top_operator, rpn_arith_expr, pos);
		stack_top_operator = (t_operator*)bsm_stack_peek(*operators);
		if (stack_top_operator)
		{
			pos->rpn_pos++;
			rpn_arith_expr[pos->rpn_pos] = TOKEN_DELIM;
			pos->rpn_pos++;
		}
	}
}

static char	*bsm_exit_state_machine(t_fsm *fsm)
{
	g_state_table[fsm->current_state][3](fsm, -1);
	if (fsm->current_state == STATE_ParseError)
		return (NULL);
	bsm_pop_operator_stack(fsm, fsm->rpn_arith_expr, fsm->pos,
		&(fsm->operators));
	if (fsm->current_state == STATE_ParseError)
		return (NULL);
	fsm->rpn_arith_expr[fsm->pos->rpn_pos + 1] = '\0';
	return (strip_whitespace(fsm->rpn_arith_expr));
}

/*
** FINITE STATE MACHINE | SHUNTING YARD ALGORITHM
** convert infix arithmetic expression to reverse polish notation
*/

char		*bsm_infix_to_rpn(const char *infix_arith_expr, int expr_len)
{
	t_fsm		*fsm;
	t_position	*pos;
	int			c;

	fsm = NULL;
	pos = &(t_position){.infix_pos = 0, .rpn_pos = 0};
	if (!bsm_init_state_machine(&fsm, expr_len, pos))
		return (NULL);
	while (fsm->current_state != STATE_ParseError &&
			fsm->current_state != STATE_EndOfData &&
			fsm->pos->infix_pos < expr_len)
	{
		c = bsm_get_next_char(infix_arith_expr, pos);
		fsm->current_event = bsm_get_new_event(c);
		g_state_table[fsm->current_state][fsm->current_event](fsm, c);
	}
	return (bsm_exit_state_machine(fsm));
}
