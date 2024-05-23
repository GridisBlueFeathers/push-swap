/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:35:58 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 21:31:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"

void	case_two(t_stack *stack_a)
{
	if (stack_a->head->value > stack_a->tail->value)
		rotate_stack(stack_a, 'v');
}

void	case_three(t_stack *stack_a)
{
	if (stack_a->head->value > stack_a->head->next->value
		&& stack_a->head->value > stack_a->tail->value)
		rotate_stack(stack_a, 'v');
	if (stack_a->head->value < stack_a->head->next->value
		&& stack_a->head->next->value < stack_a->tail->value)
		return ;
	if ((stack_a->head->value < stack_a->head->next->value)
		|| (stack_a->head->value > stack_a->head->next->value))
		swap_stack(stack_a, 'v');
	case_three(stack_a);
}

int	algo(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->len == 1)
		return (1);
	if (stack_a->len == 2)
		return (case_two(stack_a), 1);
	if (stack_a->len == 3)
		return (case_three(stack_a), 1);
	while (stack_a->len != 3)
		push_stack(stack_b, stack_a);
	case_three(stack_a);
	return (1);
}
