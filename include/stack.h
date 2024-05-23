/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:42:14 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 21:31:18 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_stack_node
{
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	int					valid;
	int					value;
	int					top_cost;
	int					index;
}	t_stack_node;

typedef struct s_stack
{
	size_t			len;
	t_stack_node	*head;
	t_stack_node	*tail;
	char			label;
}	t_stack;

t_stack	*stack_init(char label);
int		stack_append(t_stack *stack, char *arg);
void	stack_free(t_stack *stack);
void	print_stack_op(t_stack *stack, char *fmt, char arg);
void	print_stack(t_stack *stack);

int		swap_stack(t_stack *stack, char arg);
void	swap_stacks(t_stack *stack_a, t_stack *stack_b);

int		push_stack(t_stack *stack_to, t_stack *stack_from);

int		rotate_stack(t_stack *stack, char arg);
int		rev_rotate_stack(t_stack *stack, char arg);
void	rotate_stacks(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate_stacks(t_stack *stack_a, t_stack *stack_b);

#endif // !STACK_H
