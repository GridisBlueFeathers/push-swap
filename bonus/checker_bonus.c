/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:07:27 by svereten          #+#    #+#             */
/*   Updated: 2024/06/13 17:06:50 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "utils_bonus.h"
#include "arg_bonus.h"
#include "stack_bonus.h"
#include "get_next_line.h"
#include "ft_printf.h"

int	perform_op(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		return (push_stack(stack_a, stack_b), 1);
	if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		return (push_stack(stack_b, stack_a), 1);
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		return (swap_stack(stack_a, 'v'), 1);
	if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		return (swap_stack(stack_b, 'v'), 1);
	if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		return (swap_stacks(stack_a, stack_b), 1);
	if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		return (rotate_stack(stack_a, 'v'), 1);
	if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		return (rotate_stack(stack_b, 'v'), 1);
	if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		return (rev_rotate_stack(stack_a, 'v'), 1);
	if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		return (rev_rotate_stack(stack_b, 'v'), 1);
	if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		return (rotate_stacks(stack_a, stack_b), 1);
	if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		return (rev_rotate_stacks(stack_a, stack_b), 1);
	return (0);
}

int	parse_ops(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	int		check;

	line = get_next_line(STDIN_FILENO);
	check = 1;
	while (line && check)
	{
		if (check && line && line[0] && !perform_op(stack_a, stack_b, line))
			check = 0;
		ft_free_n_null((void **)&line);
		line = get_next_line(STDIN_FILENO);
	}
	ft_free_n_null((void **)&line);
	return (check);
}

int	main(int argc, char **argv)
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
	if (!parse_ops(stack_a, stack_b))
		return (stacks_free(stack_a, stack_b), print_error(), 1);
	if (stack_is_sorted_good(stack_a) && !stack_b->len)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (stacks_free(stack_a, stack_b), 0);
}
