/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:26:15 by svereten          #+#    #+#             */
/*   Updated: 2024/05/21 11:57:15 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include "arg.h"
#include "stack.h"

void	print_stack(t_stack_node *stack)
{
	while (stack) {
		ft_printf("%d\n", stack->value);
		ft_printf("node %p next %p prev %p\n", stack, stack->next, stack->prev);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc == 1)
		return (0);
	(void)stack_b;
	stack_a = process_args(argc, argv);
	print_stack(stack_a);
	swap_stack(&stack_a, 'a');
	print_stack(stack_a);


	return (0);
}
