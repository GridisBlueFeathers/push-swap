/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:45:41 by svereten          #+#    #+#             */
/*   Updated: 2024/05/26 11:05:42 by svereten         ###   ########.fr       */
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
	stack_update_index(stack);
	return (print_stack_op(stack, "r%c\n", arg), 0);
}

int	rev_rotate_stack(t_stack *stack, char arg)
{
	t_stack_node	*temp;

	if (!stack->head)
		return (print_stack_op(stack, "rr%c\n", arg), 0);
	temp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	stack->head->prev = temp;
	temp->prev = NULL;
	temp->next = stack->head;
	stack->head = temp;
	stack_update_index(stack);
	return (print_stack_op(stack, "rr%c\n", arg), 0);
}

void	rotate_stacks(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a, 'q');
	rotate_stack(stack_b, 'q');
	ft_printf("rr\n");
}

void	rev_rotate_stacks(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate_stack(stack_a, 'q');
	rev_rotate_stack(stack_b, 'q');
	ft_printf("rrr\n");
}
