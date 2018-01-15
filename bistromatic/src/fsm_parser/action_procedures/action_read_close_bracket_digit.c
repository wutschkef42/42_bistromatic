/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_close_bracket_digit.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:58:05 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 13:58:07 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_close_bracket_digit(t_fsm *fsm, int c)
{
	(void)c;
	fsm->current_state = STATE_ParseError;
}
