/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_operator_add.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:05:47 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 14:05:48 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	action_read_operator_add(t_fsm *fsm, int c)
{
	(void)c;
	fsm->current_state = STATE_ReadSign;
}
