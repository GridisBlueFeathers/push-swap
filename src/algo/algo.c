/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:35:58 by svereten          #+#    #+#             */
/*   Updated: 2024/05/26 11:10:51 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"

void	algo_top_node(t_stack *stack, t_stack_node *node)
{
	if (!stack || !stack->head || !node)
		return ;
	//printf("%d\n", node->value);
	if (stack->head->value == node->value)
		return ;
	else if (node->index > stack->len / 2)
		rev_rotate_stack(stack, 'v');
	else
		rotate_stack(stack, 'v');
	stack_update_index(stack);
	algo_top_node(stack, node);
}

void	algo_case_two(t_stack *stack_a)
{
	if (stack_a->head->value > stack_a->tail->value)
		rotate_stack(stack_a, 'v');
}

void	algo_case_three(t_stack *stack_a)
{
	if (stack_a->head->value > stack_a->head->next->value
		&& stack_a->head->value > stack_a->tail->value)
		rotate_stack(stack_a, 'v');
	if (stack_is_sorted_good(stack_a))
		return ;
	if (stack_is_sorted_bad(stack_a))
	{
		algo_top_node(stack_a, stack_find_smallest(stack_a));
		return;
	}
	if ((stack_a->head->value < stack_a->head->next->value)
		|| (stack_a->head->value > stack_a->head->next->value))
		swap_stack(stack_a, 'v');
	algo_case_three(stack_a);
}

void	algo_calc_below(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*smallest;
	t_stack_node	*cur_a;
	t_stack_node	*cur_b;

	if (!stack_a || !stack_b || !stack_a->head || !stack_b->head)
		return ;
	cur_b = stack_b->head;
	smallest = stack_find_smallest(stack_a);
	while (cur_b)
	{
		cur_a = stack_a->head;
		cur_b->below = smallest;
		while (cur_a)
		{
			if (cur_a->value > cur_b->value)
			{
				if (cur_b->below == smallest && cur_b->value > smallest->value)
					cur_b->below = cur_a;
				if (cur_b->below->value > cur_a->value)
					cur_b->below = cur_a;
			}
			cur_a = cur_a->next;
		}
		cur_b = cur_b->next;
	}
}

void	algo_calc_base_cost(t_stack *stack)
{
	t_stack_node	*cur;

	if (!stack || !stack->head)
		return ;
	cur = stack->head;
	while (cur)
	{
		if (cur->index < stack->len / 2)
			cur->top_cost = cur->index;
		else if (cur->index == 1)
			cur->top_cost = 1;
		else
			cur->top_cost = stack->len - cur->index;
		cur = cur->next;
	}
}

void	algo_calc_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*cur;

	if (!stack_a || !stack_b || !stack_a->head || !stack_b->head)
		return ;
	algo_calc_base_cost(stack_a);
	cur = stack_b->head;
	while (cur)
	{
		if (cur->index < stack_b->len / 2)
			cur->top_cost = cur->index;
		else if (cur->index == 1)
			cur->top_cost = 1;
		else
			cur->top_cost = stack_b->len - cur->index;
		cur->top_cost += cur->below->top_cost + 1;
		cur = cur->next;
	}
}

void	algo_top_a_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*cheapest;

	cheapest = stack_find_cheapest(stack_b);
	algo_top_node(stack_a, cheapest->below);
	algo_top_node(stack_b, cheapest);
	push_stack(stack_a, stack_b);
}

int	algo(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	if (stack_a->len == 1)
		return (1);
	if (stack_a->len == 2)
		return (algo_case_two(stack_a), 1);
	if (stack_a->len == 3)
		return (algo_case_three(stack_a), 1);
	while (stack_a->len != 3)
		push_stack(stack_b, stack_a);
	algo_case_three(stack_a);
	algo_calc_below(stack_a, stack_b);
	algo_calc_costs(stack_a, stack_b);
	i = 0;
	while (stack_b->len && !i)
	{
		algo_top_a_cheapest(stack_a, stack_b);
		algo_calc_below(stack_a, stack_b);
		algo_calc_costs(stack_a, stack_b);
		//i++;
	}
	algo_top_node(stack_a, stack_find_smallest(stack_a));
	return (1);
}
