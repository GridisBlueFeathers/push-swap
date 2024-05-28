/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_append_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:43:10 by svereten          #+#    #+#             */
/*   Updated: 2024/05/28 14:41:20 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "stack_bonus.h"
#include "arg_bonus.h"

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
		res->index = 0;
		return (1);
	}
	res->prev = cur;
	res->index = cur->index + 1;
	cur->next = res;
	stack->tail = res;
	return (1);
}
