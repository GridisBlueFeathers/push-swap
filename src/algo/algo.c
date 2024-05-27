/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:35:58 by svereten          #+#    #+#             */
/*   Updated: 2024/05/27 20:31:09 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"
#include "algo.h"

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
		cur->top_cost = 2147483647;
		algo_calc_up_up(cur);
		algo_calc_down_down(stack_a, stack_b, cur);
		algo_calc_up_down(stack_b, cur);
		algo_calc_down_up(stack_a, cur);
		cur = cur->next;
	}
}

void	algo_top_a_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*cheapest;

	cheapest = stack_find_cheapest(stack_b);
	if (cheapest->rotation_mode == 1)
		algo_top_up_up(stack_a, stack_b, cheapest);
	if (cheapest->rotation_mode == 2)
		algo_top_down_down(stack_a, stack_b, cheapest);
	if (cheapest->rotation_mode == 3)
		algo_top_up_down(stack_a, stack_b, cheapest);
	if (cheapest->rotation_mode == 4)
		algo_top_down_up(stack_a, stack_b, cheapest);
}

int	algo(t_stack *stack_a, t_stack *stack_b)
{
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
	while (stack_b->len)
	{
		algo_top_a_cheapest(stack_a, stack_b);
		algo_calc_below(stack_a, stack_b);
		algo_calc_costs(stack_a, stack_b);
	}
	algo_top_node(stack_a, stack_find_smallest(stack_a));
	return (1);
}
