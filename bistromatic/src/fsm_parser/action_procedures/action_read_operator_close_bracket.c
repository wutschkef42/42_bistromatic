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

void    action_read_operator_close_bracket(t_fsm *fsm, int c)
{
    (void)c;
    fsm->current_state = STATE_ParseError;
}
