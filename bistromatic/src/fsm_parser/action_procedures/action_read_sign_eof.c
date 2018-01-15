/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_sign_eof.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:11:35 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 14:11:37 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_sign_eof(t_fsm *fsm, int c)
{
	(void)c;
	fsm->current_state = STATE_ParseError;
}
