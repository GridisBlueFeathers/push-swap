/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:45:41 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 11:49:17 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"

int	rotate_stack(t_stack *stack, char arg)
{
	t_stack_node	*temp;
	if (!stack->head)
		return (print_stack_op(stack, "r%c\n", arg), 0);
	temp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = temp;
	temp->next = NULL;
	temp->prev = stack->tail;
	stack->tail = temp;
	return (print_stack_op(stack, "r%c\n", arg), 0);
}

void	rotate_stacks(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a, 'q');
	rotate_stack(stack_b, 'q');
	ft_printf("rr\n");
}
