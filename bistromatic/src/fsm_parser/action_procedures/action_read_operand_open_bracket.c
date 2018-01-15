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
** opening brackets cannot appear after digits
** so throw a syntax error
*/

void    action_read_operand_open_bracket(t_fsm *fsm, int c)
{
    (void)c;
    fsm->current_state = STATE_ParseError;
}
