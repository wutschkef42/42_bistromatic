/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_operand_open_bracket.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:04:49 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 14:04:50 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

/*
** opening brackets cannot appear after digits
** so throw a syntax error
*/

void	action_read_operand_open_bracket(t_fsm *fsm, int c)
{
	(void)c;
	fsm->current_state = STATE_ParseError;
}
