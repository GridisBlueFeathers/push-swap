/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:55:47 by svereten          #+#    #+#             */
/*   Updated: 2024/05/28 14:37:58 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack_bonus.h"
#include "libft.h"

int	validate_arg(t_stack *stack, char *arg, int *valid)
{
	int				arg_num;
	size_t			arg_len;
	t_stack_node	*cur;

	arg_num = ft_atoi(arg);
	arg_len = ft_strlen(arg);
	if ((ft_intlen(arg_num) != arg_len)
		|| (arg[0] == '-' && arg_len == 1))
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

void	free_split(char **argv, int split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (argv[i])
	{
		ft_free_n_null((void **)&argv[i]);
		i++;
	}
	ft_free_n_null((void **)&argv);
}

int	process_args(size_t argc, char **argv, t_stack *stack)
{
	size_t	i;
	int		split;

	i = 1;
	split = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		i = 0;
		split = 1;
	}
	while (i < argc)
	{
		if (!stack_append(stack, argv[i]))
			return (free_split(argv, split), 0);
		i++;
	}
	return (free_split(argv, split), 1);
}
