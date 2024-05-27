/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:30:59 by svereten          #+#    #+#             */
/*   Updated: 2024/05/27 20:31:49 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "algo.h"

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
		return ;
	}
	if ((stack_a->head->value < stack_a->head->next->value)
		|| (stack_a->head->value > stack_a->head->next->value))
		swap_stack(stack_a, 'v');
	algo_case_three(stack_a);
}
