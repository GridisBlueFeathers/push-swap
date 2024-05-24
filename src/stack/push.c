/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:13:44 by svereten          #+#    #+#             */
/*   Updated: 2024/05/24 17:38:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"

int	push_stack(t_stack *stack_to, t_stack *stack_from)
{
	t_stack_node	*temp;

	if (!stack_from->head)
		return (ft_printf("p%c\n", stack_to->label), 0);
	temp = stack_from->head;
	stack_from->head = stack_from->head->next;
	if (stack_from->head)
		stack_from->head->prev = NULL;
	temp->next = stack_to->head;
	if (!stack_to->tail)
		stack_to->tail = temp;
	if (stack_to->head)
		stack_to->head->prev = temp;
	stack_to->head = temp;
	stack_to->len += 1;
	stack_from->len -= 1;
	stack_update_index(stack_to);
	stack_update_index(stack_from);
	return (ft_printf("p%c\n", stack_to->label), 1);
}
