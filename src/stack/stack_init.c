/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:45:37 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 11:16:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "libft.h"
#include "arg.h"

t_stack	*stack_init(char label)
{
	t_stack	*res;

	res = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!res)
		return (NULL);
	res->len = 0;
	res->label = label;
	res->head = NULL;
	res->tail = NULL;
	return (res);
}
