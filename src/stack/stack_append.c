/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:43:10 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 11:16:19 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "stack.h"
#include "arg.h"

int	stack_append(t_stack *stack, char *arg)
{
	t_stack_node	*res;
	t_stack_node	*cur;

	res = (t_stack_node *)ft_calloc(1, sizeof(t_stack_node));
	if (!res)
		return (0);
	res->value = validate_arg(stack, arg, &res->valid);
	if (!res->valid)
		return (free(res), 0);
	cur = stack->tail;
	stack->len += 1;
	if (!cur)
	{
		stack->head = res;
		stack->tail = res;
		return (1);
	}
	res->prev = cur;
	cur->next = res;
	stack->tail = res;
	return (1);
}
