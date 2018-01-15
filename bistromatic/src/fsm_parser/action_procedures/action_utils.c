/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:57:36 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:58:12 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"

void	    bsm_set_op_type(char op_token, t_operator *operator, t_state current_state)
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
        if (current_state == STATE_ReadOperand || current_state == STATE_ReadCloseBracket)
            operator->op_type = SUB;
        else
            operator->op_type = MSIGN;
    }
	else
		bsm_putstr("syntax error", 2);
}

void	    bsm_set_op_precedence(t_operator *operator)
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

void	    bsm_enqueue_operator(t_operator *stack_top_operator, char *rpn_arith_expr, t_position *pos)
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

void preprocess_stack(t_fsm *fsm, t_operator *new_operator)
{
    t_operator  *stack_top_operator;

    stack_top_operator = (t_operator*)bsm_stack_peek(fsm->operators);
    while (stack_top_operator && stack_top_operator->op_type != OPEN_BRK && stack_top_operator->precedence >= new_operator->precedence)
    {
		if (stack_top_operator->op_type == MSIGN && new_operator->op_type == MSIGN)
			break ;
        stack_top_operator = (t_operator*)bsm_stack_pop(&(fsm->operators));
        if (stack_top_operator)
        {
            bsm_enqueue_operator(stack_top_operator, fsm->rpn_arith_expr, fsm->pos);
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

void    pop_til_open_bracket(t_fsm *fsm, int c)
{
    t_operator  *stack_top_operator;

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


void    insert_new_operator(t_fsm *fsm, t_operator *new_operator)
{
    t_operator  *stack_top_operator;
    
    if (!(fsm->operators))
    {
        bsm_stack_push(&(fsm->operators), bsm_stack_new((void*)new_operator, sizeof(t_operator)));
        return ;
    }
    stack_top_operator = (t_operator*)bsm_stack_peek(fsm->operators);
    preprocess_stack(fsm, new_operator);
	bsm_stack_push(&(fsm->operators), bsm_stack_new((void*)new_operator, sizeof(t_operator)));
}

/*
**	void    bsm_add_char_to_current_token(t_fsm *fsm, int c)
**	if (fsm->current_token_length < sizeof(fsm->token_buffer))
**	fsm->token_buffer[fsm->current_token_length++] = (char)c;
**	void    bsm_print_current_token(t_fsm *fsm)
**	printf(">> Token (length: %2d):\t[%s]\n", (int)(fsm->current_token_length), fsm->token_buffer);
**	fsm_current_token_length = 0;
*/
