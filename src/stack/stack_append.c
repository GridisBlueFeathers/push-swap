/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:43:10 by svereten          #+#    #+#             */
/*   Updated: 2024/05/19 14:21:00 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "stack.h"
#include "arg.h"

t_stack_node	*stack_append(t_stack_node **start, char *arg)
{
	t_stack_node	*res;
	t_stack_node	*cur;

	res = (t_stack_node *)ft_calloc(1, sizeof(t_stack_node));
	if (!res)
		return (NULL);
	res->len = 0;
	res->value = validate_arg(arg, &res->valid);
	if (!res->valid)
		return (free(res), NULL);
	cur = *start;
	while (cur->next)
	{
		if (res->value == cur->value)
			return (free(res), NULL);
		cur = cur->next;
	}
	res->prev = cur;
	cur->next = res;
	return (res);

}
