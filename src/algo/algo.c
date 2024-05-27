/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:35:58 by svereten          #+#    #+#             */
/*   Updated: 2024/05/27 19:33:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"

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

void	algo_calc_up_up(t_stack_node **cur)
{
	int	res;
	t_stack_node	*node;

	node = *cur;
	if (node->index > node->below->index)
		res = node->index + 1;
	else
		res = node->below->index + 1;
	if (res < node->top_cost)
	{
		node->top_cost = res;
		node->rotation_mode = 1;
	}
}

void	algo_calc_down_down(t_stack *a, t_stack *b, t_stack_node **cur)
{
	int	res;
	t_stack_node	*node;

	node = *cur;
	if (b->len - node->index > a->len - node->below->index)
		res = b->len - node->index + 1;
	else
		res = a->len - node->below->index + 1;
	if (res < node->top_cost)
	{
		node->top_cost = res;
		node->rotation_mode = 2;
	}
}

void	algo_calc_up_down(t_stack *b, t_stack_node **cur)
{
	int	res;
	t_stack_node	*node;

	node = *cur;
	res = node->below->index + (b->len - node->index) + 1;
	if (res < node->top_cost)
	{
		node->top_cost = res;
		node->rotation_mode = 3;
	}
}

void	algo_calc_down_up(t_stack *a, t_stack_node **cur)
{
	int	res;
	t_stack_node	*node;

	node = *cur;
	res = (a->len - node->below->index) + node->index + 1;
	if (res < node->top_cost)
	{
		node->top_cost = res;
		node->rotation_mode = 4;
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
		algo_calc_up_up(&cur);
		algo_calc_down_down(stack_a, stack_b, &cur);
		algo_calc_up_down(stack_b, &cur);
		algo_calc_down_up(stack_a, &cur);
		cur = cur->next;
	}
}

void	algo_top_one_direction(t_stack *a, t_stack *b, t_stack_node *c)
{
	if ((c->index > b->len / 2) && (c->below->index > a->len / 2))
		while ((b->head->value != c->value)
			&& (a->head->value != c->below->value))
			rev_rotate_stacks(a, b);
	else if (c->index <= b->len / 2 && c->below->index <= a->len /2)
		while ((b->head->value != c->value)
			&& (a->head->value != c->below->value))
			rotate_stacks(a, b);
}

void	algo_top_up_up(t_stack *a, t_stack *b, t_stack_node *c)
{
	while (b->head->value != c->value && a->head->value != c->below->value)
		rotate_stacks(a, b);
	algo_top_node(a, c->below);
	algo_top_node(b, c);
	push_stack(a, b);
}

void	algo_top_down_down(t_stack *a, t_stack *b, t_stack_node *c)
{
	while (b->head->value != c->value && a->head->value != c->below->value)
		rev_rotate_stacks(a, b);
	algo_top_node(a, c->below);
	algo_top_node(b, c);
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

void	algo_top_a_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*cheapest;

	cheapest = stack_find_cheapest(stack_b);
	//printf("%d\n", cheapest->top_cost);
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
