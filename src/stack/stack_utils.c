/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:23:18 by svereten          #+#    #+#             */
/*   Updated: 2024/05/24 16:19:35 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "stack.h"
#include "libft.h"

int	stack_is_sorted_good(t_stack *stack)
{
	t_stack_node	*cur;

	if (!stack || !stack->head)
		return (-1);
	cur = stack->head;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

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

int	stack_is_sorted_bad(t_stack *stack)
{
	t_stack_node	*cur;
	t_stack_node	*smallest;

	if (!stack || !stack->head)
		return (-1);
	cur = stack->head;
	smallest = stack_find_smallest(stack);
	if (stack->tail->value > stack->head->value)
		return (0);
	while (cur->next)
	{
		if ((cur->value > cur->next->value)
			&& (cur->next != smallest))
				return (0);
		cur = cur->next;
	}
	return (1);
}

void	stack_update_index(t_stack *stack)
{
	t_stack_node	*cur;
	int				i;

	if (!stack || !stack->head)
		return ;
	cur = stack->head;
	i = 0;
	while (cur)
	{
		cur->index = i;
		cur = cur->next;
		i++;
	}
}

void	stack_free(t_stack *stack)
{
	t_stack_node	*cur;
	t_stack_node	*temp;

	if (!stack)
		return ;
	cur = stack->head;
	while (cur)
	{
		temp = cur->next;
		ft_free_n_null((void **)&cur);
		cur = temp;
	}
	stack->head = NULL;
	stack->tail = NULL;
	ft_free_n_null((void **)&stack);
}

void print_stack(t_stack *stack)
{
	t_stack_node *cur;

	cur = stack->head;
	while (cur) {
		ft_printf("%d\n", cur->value);
		cur = cur->next;
	}
}
