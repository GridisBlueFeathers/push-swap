/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:55:47 by svereten          #+#    #+#             */
/*   Updated: 2024/05/19 14:32:46 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "stack.h"

int	validate_arg(char *arg, int *valid)
{
	int		arg_num;
	size_t	arg_len;

	arg_num = ft_atoi(arg);
	arg_len = ft_strlen(arg);
	if ((ft_intlen(arg_num) != arg_len)
		|| (arg[0] == '-' && arg_len))
	{
		*valid = 0;
		return (0);
	}
	*valid = 1;
	return (arg_num);
}

t_stack_node *process_args(size_t args_amount, char **argv)
{
	t_stack_node	*res;
	t_stack_node	*cur;
	size_t			i;

	res = stack_init(argv[1]);
	cur = res;
	i = 2;
	while (i < args_amount)
	{
		cur = stack_append(&res, argv[i]);
		if (!cur)
			//TODO: free stack
			return (NULL);
		i++;
	}
	return (res);
}
