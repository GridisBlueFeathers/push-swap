/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:55:47 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 11:11:49 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "stack.h"

int	validate_arg(t_stack *stack, char *arg, int *valid)
{
	int				arg_num;
	size_t			arg_len;
	t_stack_node	*cur;

	arg_num = ft_atoi(arg);
	arg_len = ft_strlen(arg);
	if ((ft_intlen(arg_num) != arg_len)
		|| (arg[0] == '-' && arg_len))
	{
		*valid = 0;
		return (0);
	}
	cur = stack->head;
	while (cur)
	{
		if (cur->value == arg_num)
		{
			*valid = 0;
			return (0);
		}
		cur = cur->next;
	}
	*valid = 1;
	return (arg_num);
}

int	process_args(size_t args_amount, char **argv, t_stack *stack)
{
	size_t			i;

	i = 1;
	while (i < args_amount)
	{
		if (!stack_append(stack, argv[i]))
			//TODO: free stack
			return (0);
		i++;
	}
	return (1);
}
