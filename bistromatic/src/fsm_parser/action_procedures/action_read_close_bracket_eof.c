/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_close_bracket_eof.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:59:03 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 13:59:05 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_close_bracket_eof(t_fsm *fsm, int c)
{
	(void)c;
	fsm->current_state = STATE_EndOfData;
}
