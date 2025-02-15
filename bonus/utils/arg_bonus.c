/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:55:47 by svereten          #+#    #+#             */
/*   Updated: 2024/06/14 11:45:17 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack_bonus.h"
#include "libft.h"

int	validate_arg(t_stack *stack, char *arg, int *valid)
{
	int				arg_num;
	t_stack_node	*cur;

	if (!ft_validate_atoi(arg, &arg_num))
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
		if (!argv)
			return (0);
		i = 0;
		split = 1;
	}
	while (argv[i])
	{
		if (!stack_append(stack, argv[i]))
			return (free_split(argv, split), 0);
		i++;
	}
	return (free_split(argv, split), 1);
}
