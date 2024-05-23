/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:13:44 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 10:23:26 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"

int	push_stack(t_stack *stack_a, t_stack *stack_b, char s)
{
	t_stack_node *temp;

	if (s == 'a')
	{
		if (!stack_b->head)
			return (ft_printf("pa\n"), 0);
		temp = stack_b->head;
		stack_b->head = stack_b->head->next;
		temp->next = stack_a->head;
		stack_a->head->prev = temp;
		stack_a->head = temp;
		stack_a->len += 1;
		stack_b->len -= 1;
		return (ft_printf("pa\n"), 0);
	}
	return (1);
}
