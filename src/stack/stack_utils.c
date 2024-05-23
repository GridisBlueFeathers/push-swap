/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:23:18 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 15:03:47 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "libft.h"

void	stack_free(t_stack *stack)
{
	t_stack_node	*cur;
	t_stack_node	*temp;

	if (!stack)
		return ;
	cur = stack->head;
	while (cur)
	{
		temp = cur->next;
		ft_free_n_null((void **)&cur);
		cur = temp;
	}
	stack->head = NULL;
	stack->tail = NULL;
	ft_free_n_null((void **)&stack);
}
