/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:42:08 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:53:23 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "bsm_tools.h"

void	bsm_free_stack_elem(t_stack *elem)
{
	free(elem->data);
	free(elem);
}

void	bsm_stack_push(t_stack **stack, t_stack *elem)
{
	if (!stack || !elem)
		return ;
	elem->next = *stack;
	*stack = elem;
}

/*
** pop element off stack
** return data content & free element
** !!! bsm_stack_pop return value is malloced, must be freed later on
*/

void	*bsm_stack_pop(t_stack **stack)
{
	void	*data;
	t_stack	*tmp;

	data = NULL;
	if (!stack || !*stack)
		return (NULL);
	data = malloc(sizeof(char) * (*stack)->data_size + 1);
	bsm_memcpy(data, (*stack)->data, (*stack)->data_size);
	tmp = *stack;
	*stack = (*stack)->next;
	if (tmp)
		bsm_free_stack_elem(tmp);
	return (data);
}

void	*bsm_stack_peek(t_stack *stack)
{
	if (!stack)
		return (NULL);
	return (stack->data);
}

t_stack	*bsm_stack_new(void *data, size_t data_size)
{
	t_stack	*new;

	if (!(new = malloc(sizeof(t_stack))))
		return (NULL);
	if (!(new->data = malloc(sizeof(char) * data_size + 1)))
		return (NULL);
	bsm_memcpy(new->data, data, data_size);
	new->data_size = data_size;
	return (new);
}
