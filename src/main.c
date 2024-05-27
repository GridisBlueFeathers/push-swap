/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:26:15 by svereten          #+#    #+#             */
/*   Updated: 2024/05/27 21:03:38 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "algo.h"
#include "arg.h"
#include "ft_printf.h"
#include "libft.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = stack_init('a');
	stack_b = stack_init('b');
	if (!stack_a || !stack_b)
		return (stacks_free(stack_a, stack_b), ft_printf("Error\n"), 1);
	if (!process_args(argc, argv, stack_a))
		return (stacks_free(stack_a, stack_b), ft_printf("Error\n"), 1);
	algo(stack_a, stack_b);
	return (stacks_free(stack_a, stack_b), 0);
}
