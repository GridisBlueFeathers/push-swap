/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:36 by svereten          #+#    #+#             */
/*   Updated: 2024/05/24 14:58:08 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "stack.h"
#include "libft.h"

int	swap_stack(t_stack *stack, char arg)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack->head || !stack->head->next)
		return (print_stack_op(stack, "s%c\n", arg), 0);
	first = stack->head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->head = second;
	if (stack->tail == stack->head)
		stack->tail = first;
	stack_update_index(stack);
	return (print_stack_op(stack, "s%c\n", arg), 1);
}

void	swap_stacks(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a, 'q');
	swap_stack(stack_b, 'q');
	ft_printf("ss\n");
}
