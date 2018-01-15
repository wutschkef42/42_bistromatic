/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:57:21 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 19:57:23 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct		s_stack
{
	void			*data;
	size_t			data_size;
	struct s_stack	*next;

}					t_stack;

void				bsm_stack_push(t_stack **stack, t_stack *elem);
void				*bsm_stack_pop(t_stack **stack);
void				*bsm_stack_peek(t_stack *stack);
t_stack				*bsm_stack_new(void *data, size_t data_size);
void				bsm_free_stack_elem(t_stack *elem);

#endif
