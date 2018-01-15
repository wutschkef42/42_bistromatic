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

void    action_read_sign_open_bracket(t_fsm *fsm, int c)
{
    t_operator  *new_operator;

    new_operator = bsm_new_operator((char)c, fsm);
    insert_new_operator(fsm, new_operator);
    fsm->current_state = STATE_ReadOpenBracket;
}
