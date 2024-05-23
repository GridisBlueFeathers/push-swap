/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:36 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 10:42:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "stack.h"
#include "libft.h"

int	swap_stack(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack->head || !stack->head->next)
	{
		return (ft_printf("s%c\n", stack->label), 0);
	}
	first = stack->head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->head = second;
	return (ft_printf("s%c\n", stack->label), 1);
}

void	swap_stacks(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("ss\n");
}
