/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:35:58 by svereten          #+#    #+#             */
/*   Updated: 2024/05/24 15:35:39 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"

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
	if ((stack_a->head->value < stack_a->head->next->value)
		|| (stack_a->head->value > stack_a->head->next->value))
		swap_stack(stack_a, 'v');
	algo_case_three(stack_a);
}

void	algo_calc_below(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;

}

int	algo(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->len == 1)
		return (1);
	if (stack_a->len == 2)
		return (algo_case_two(stack_a), 1);
	if (stack_a->len == 3)
		return (algo_case_three(stack_a), 1);
	while (stack_a->len != 3)
		push_stack(stack_b, stack_a);
	algo_case_three(stack_a);
	return (1);
}
