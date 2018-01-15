/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_close_bracket_open_bracket.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:59:49 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 13:59:51 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_close_bracket_open_bracket(t_fsm *fsm, int c)
{
	(void)c;
	fsm->current_state = STATE_ParseError;
}
