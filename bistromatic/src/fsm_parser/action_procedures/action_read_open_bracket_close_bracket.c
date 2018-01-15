/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_open_bracket_close_bracket.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:17:01 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 15:17:03 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_open_bracket_close_bracket(t_fsm *fsm, int c)
{
	pop_til_open_bracket(fsm, c);
	fsm->current_state = STATE_ReadCloseBracket;
}
