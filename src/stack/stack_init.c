/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:45:37 by svereten          #+#    #+#             */
/*   Updated: 2024/05/19 14:32:25 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "libft.h"
#include "arg.h"


t_stack_node	*stack_init(char *arg)
{
	t_stack_node	*res;

	res = (t_stack_node *)ft_calloc(1, sizeof(t_stack_node));
	if (!res)
		return (NULL);
	res->len = 0;
	res->value = validate_arg(arg, &res->valid);
	if (!res->valid)
		return (NULL);
	return (res);
}
