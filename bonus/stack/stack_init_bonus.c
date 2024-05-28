/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:45:37 by svereten          #+#    #+#             */
/*   Updated: 2024/05/28 14:28:03 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack_bonus.h"
#include "libft.h"

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
