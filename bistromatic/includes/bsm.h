/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:57:39 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:02:23 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSM_H
# define BSM_H

# include <stdlib.h>
# include <stdio.h>
# include "stack.h"

# define TOKEN_DELIM ' '

typedef enum		e_operator_type
{
	OPEN_BRK, CLOSE_BRK, MUL, DIV, MOD, ADD, SUB, MSIGN
}					t_operator_type;

typedef struct		s_operator
{
	t_operator_type	op_type;
	int				precedence;
}					t_operator;

typedef struct		s_position
{
	int				infix_pos;
	int				rpn_pos;
}					t_position;




/*
** STATE MACHINE STATES
*/
typedef enum		e_state
{
	STATE_EndOfData,
	STATE_InitState,
	STATE_ParseError,
	STATE_ReadCloseBracket,
	STATE_ReadOpenBracket,
	STATE_ReadOperand,
	STATE_ReadOperator,
	STATE_ReadSign,
	MAX_STATES
}					t_state;

/*
** STATE MACHINE EVENTS
**
** EVENT_Add -> read + character
** EVENT_Sub -> read - character
** EVENT_Op -> read *, /, % character
** EVENT_Dig -> read character from input base charset
** EVENT_Obrk -> read ( character
** EVENT_Cbrk -> read ) character
** EVENT_Eof -> read -1
*/

typedef enum		e_event
{
	EVENT_Add,
	EVENT_Cbrk,
	EVENT_Dig,
	EVENT_Eof,
	EVENT_Op,
	EVENT_Obrk,
	EVENT_Sub,
	MAX_EVENTS
}					t_event;

/*
** FINITE STATE MACHINE with stack memory
*/

typedef struct		s_fsm
{
	t_stack		*operators;
	char		*rpn_arith_expr;
	t_position	*pos;
	t_state		current_state;
	t_event		current_event;
}					t_fsm;

/* fsm parser */
t_event 			bsm_get_new_event(int c);
char				*bsm_infix_to_rpn(const char *infix_arith_expr, int expr_len);

/* action procedures */
void				action_end_of_data(t_fsm *fsm, int c);

void				action_init_state_add(t_fsm *fsm, int c);
void				action_init_state_close_bracket(t_fsm *fsm, int c);
void				action_init_state_digit(t_fsm *fsm, int c);
void				action_init_state_eof(t_fsm *fsm, int c);
void				action_init_state_op(t_fsm *fsm, int c);
void				action_init_state_open_bracket(t_fsm *fsm, int c);
void				action_init_state_sub(t_fsm *fsm, int c);

void				action_parse_error(t_fsm *fsm, int c);

void				action_read_close_bracket_close_bracket(t_fsm *fsm, int c);
void				action_read_close_bracket_digit(t_fsm *fsm, int c);
void				action_read_close_bracket_eof(t_fsm *fsm, int c);
void				action_read_close_bracket_op(t_fsm *fsm, int c);
void				action_read_close_bracket_open_bracket(t_fsm *fsm, int c);

void				action_read_open_bracket_add(t_fsm *fsm, int c);
void				action_read_open_bracket_close_bracket(t_fsm *fsm, int c);
void				action_read_open_bracket_digit(t_fsm *fsm, int c);
void				action_read_open_bracket_eof(t_fsm *fsm, int c);
void				action_read_open_bracket_op(t_fsm *fsm, int c);
void				action_read_open_bracket_open_bracket(t_fsm *fsm, int c);
void				action_read_open_bracket_sub(t_fsm *fsm, int c);

void				action_read_operand_close_bracket(t_fsm *fsm, int c);
void				action_read_operand_digit(t_fsm *fsm, int c);
void				action_read_operand_eof(t_fsm *fsm, int c);
void				action_read_operand_op(t_fsm *fsm, int c);
void				action_read_operand_open_bracket(t_fsm *fsm, int c);

void				action_read_operator_add(t_fsm *fsm, int c);
void				action_read_operator_close_bracket(t_fsm *fsm, int c);
void				action_read_operator_digit(t_fsm *fsm, int c);
void				action_read_operator_eof(t_fsm *fsm, int c);
void				action_read_operator_op(t_fsm *fsm, int c);
void				action_read_operator_open_bracket(t_fsm *fsm, int c);
void				action_read_operator_sub(t_fsm *fsm, int c);

void				action_read_sign_add(t_fsm *fsm, int c);
void				action_read_sign_close_bracket(t_fsm *fsm, int c);
void				action_read_sign_digit(t_fsm *fsm, int c);
void				action_read_sign_eof(t_fsm *fsm, int c);
void				action_read_sign_op(t_fsm *fsm, int c);
void				action_read_sign_open_bracket(t_fsm *fsm, int c);
void				action_read_sign_sub(t_fsm *fsm, int c);

/* action utils */
void				insert_new_operator(t_fsm *fsm, t_operator *new_operator);
void				pop_til_open_bracket(t_fsm *fsm, int c);
void				preprocess_stack(t_fsm *fsm, t_operator *new_operator);
t_operator			*bsm_new_operator(char op_token, t_fsm *fsm);
 void				bsm_enqueue_operand_digit(t_fsm *fsm, int c);
 void				bsm_enqueue_operator(t_operator *stack_top_operator, char *rpn_arith_expr, t_position *pos);
 void				bsm_set_op_precedence(t_operator *operator);
 void				bsm_set_op_type(char op_token, t_operator *operator, t_state current_state);


/* read and eval stuff */
int					bsm_parse_commandline_args(int ac, char **av,
						int *stdin_len, char **charset);
int					bsm_read_stdin(char **arith_expr, char *charset,
						int expr_len);
int					bsm_is_operator(char c);
char				**bsm_tokenize(const char *s);
void				bsm_print_tokens(char **tokens);
char				*bsm_rpn_eval(char *rpn_arith_expr, char *charset);

#endif
