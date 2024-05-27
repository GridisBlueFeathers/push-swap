/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:29:41 by svereten          #+#    #+#             */
/*   Updated: 2024/05/28 00:02:30 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "algo.h"
#include "arg.h"
#include "libft.h"
#include "stack.h"
#include "utils.h"

int	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = stack_init('a');
	stack_b = stack_init('b');
	if (!stack_a || !stack_b)
		return (stacks_free(stack_a, stack_b), print_error(), 1);
	if (!process_args(argc, argv, stack_a))
		return (stacks_free(stack_a, stack_b), print_error(), 1);
	algo(stack_a, stack_b);
	return (stacks_free(stack_a, stack_b), 0);
}
