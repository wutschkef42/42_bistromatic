/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_read_close_bracket_close_bracket.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:57:50 by fwutschk          #+#    #+#             */
/*   Updated: 2018/01/15 13:57:52 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

/*
** pop operators off operator stack until first '('
** enqueue popped operators to output string
*/

void	action_read_close_bracket_close_bracket(t_fsm *fsm, int c)
{
	pop_til_open_bracket(fsm, c);
}
