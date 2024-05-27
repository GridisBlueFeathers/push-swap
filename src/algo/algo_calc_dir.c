/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_calc_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:17:14 by svereten          #+#    #+#             */
/*   Updated: 2024/05/27 20:20:16 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

void	algo_calc_up_up(t_stack_node *node)
{
	int				res;

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

void	algo_calc_down_down(t_stack *a, t_stack *b, t_stack_node *node)
{
	int	res;

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

void	algo_calc_up_down(t_stack *b, t_stack_node *node)
{
	int	res;

	res = node->below->index + (b->len - node->index) + 1;
	if (res < node->top_cost)
	{
		node->top_cost = res;
		node->rotation_mode = 3;
	}
}

void	algo_calc_down_up(t_stack *a, t_stack_node *node)
{
	int	res;

	res = (a->len - node->below->index) + node->index + 1;
	if (res < node->top_cost)
	{
		node->top_cost = res;
		node->rotation_mode = 4;
	}
}
