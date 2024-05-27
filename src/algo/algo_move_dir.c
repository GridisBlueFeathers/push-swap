/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:24:58 by svereten          #+#    #+#             */
/*   Updated: 2024/05/27 20:30:20 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

void	algo_top_node(t_stack *stack, t_stack_node *node)
{
	if (!stack || !stack->head || !node)
		return ;
	while (stack->head->value != node->value)
	{
		if (node->index > stack->len / 2)
			rev_rotate_stack(stack, 'v');
		else
			rotate_stack(stack, 'v');
		stack_update_index(stack);
	}
}

void	algo_top_up_up(t_stack *a, t_stack *b, t_stack_node *c)
{
	while (b->head->value != c->value && a->head->value != c->below->value)
		rotate_stacks(a, b);
	while (a->head->value != c->below->value)
		rotate_stack(a, 'v');
	while (b->head->value != c->value)
		rotate_stack(b, 'v');
	push_stack(a, b);
}

void	algo_top_down_down(t_stack *a, t_stack *b, t_stack_node *c)
{
	while (b->head->value != c->value && a->head->value != c->below->value)
		rev_rotate_stacks(a, b);
	while (a->head->value != c->below->value)
		rev_rotate_stack(a, 'v');
	while (b->head->value != c->value)
		rev_rotate_stack(b, 'v');
	push_stack(a, b);
}

void	algo_top_up_down(t_stack *a, t_stack *b, t_stack_node *c)
{
	while (a->head->value != c->below->value)
		rotate_stack(a, 'v');
	while (b->head->value != c->value)
		rev_rotate_stack(b, 'v');
	push_stack(a, b);
}

void	algo_top_down_up(t_stack *a, t_stack *b, t_stack_node *c)
{
	while (a->head->value != c->below->value)
		rev_rotate_stack(a, 'v');
	while (b->head->value != c->value)
		rotate_stack(b, 'v');
	push_stack(a, b);
}
