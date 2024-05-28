/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:38:24 by svereten          #+#    #+#             */
/*   Updated: 2024/05/28 14:34:58 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack_bonus.h"

t_stack_node	*stack_find_smallest(t_stack *stack)
{
	t_stack_node	*cur;
	t_stack_node	*smallest;

	if (!stack || !stack->head)
		return (NULL);
	cur = stack->head;
	smallest = stack->head;
	while (cur)
	{
		if (cur->value < smallest->value)
			smallest = cur;
		cur = cur->next;
	}
	return (smallest);
}

t_stack_node	*stack_find_cheapest(t_stack *stack)
{
	t_stack_node	*cur;
	t_stack_node	*cheapest;

	if (!stack || !stack->head)
		return (NULL);
	cur = stack->head;
	cheapest = stack->head;
	while (cur)
	{
		if (cur->top_cost < cheapest->top_cost)
			cheapest = cur;
		cur = cur->next;
	}
	return (cheapest);
}
