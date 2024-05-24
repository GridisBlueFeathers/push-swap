/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:23:18 by svereten          #+#    #+#             */
/*   Updated: 2024/05/24 14:57:23 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "stack.h"
#include "libft.h"

void	stack_update_index(t_stack *stack)
{
	t_stack_node	*cur;
	int				i;

	if (!stack || !stack->head)
		return ;
	cur = stack->head;
	i = 0;
	while (cur)
	{
		cur->index = i;
		cur = cur->next;
		i++;
	}
}

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

void print_stack(t_stack *stack)
{
	t_stack_node *cur;

	cur = stack->head;
	while (cur) {
		ft_printf("%d\n", cur->value);
		cur = cur->next;
	}
}
