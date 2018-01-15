/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arith_expr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:55:50 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:55:52 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

/*
** pop operators off operator stack until first '('
** enqueue popped operators to output string
*/

void    action_read_operand_close_bracket(t_fsm *fsm, int c)
{
    (fsm->rpn_arith_expr)[fsm->pos->rpn_pos] = TOKEN_DELIM;
    fsm->pos->rpn_pos++;
    pop_til_open_bracket(fsm, c);
    
    
    fsm->current_state = STATE_ReadCloseBracket;
}
