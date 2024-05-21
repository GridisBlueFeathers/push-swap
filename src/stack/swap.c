/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:50:36 by svereten          #+#    #+#             */
/*   Updated: 2024/05/21 11:56:45 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "stack.h"
#include "libft.h"

void	swap_stack(t_stack_node **stack, char s)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
	if (s == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}
