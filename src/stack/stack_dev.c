/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:37:21 by svereten          #+#    #+#             */
/*   Updated: 2024/05/27 20:37:50 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"

void	print_stack(t_stack *stack)
{
	t_stack_node	*cur;

	cur = stack->head;
	while (cur)
	{
		ft_printf("%d\n", cur->value);
		cur = cur->next;
	}
}
