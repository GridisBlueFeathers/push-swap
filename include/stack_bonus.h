/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:14:50 by svereten          #+#    #+#             */
/*   Updated: 2024/05/28 22:48:12 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STACK_BONUS_H
# define STACK_BONUS_H

# include "libft.h"

typedef struct s_stack_node
{
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	struct s_stack_node	*below;
	int					valid;
	int					value;
	int					top_cost;
	int					rotation_mode;
	size_t				index;
}	t_stack_node;

typedef struct s_stack
{
	size_t			len;
	t_stack_node	*head;
	t_stack_node	*tail;
	char			label;
}	t_stack;

t_stack			*stack_init(char label);
int				stack_append(t_stack *stack, char *arg);
void			stack_free(t_stack *stack);
void			stacks_free(t_stack *stack_a, t_stack *stack_b);
void			stack_update_index(t_stack *stack);
int				stack_is_sorted_good(t_stack *stack);
int				stack_is_sorted_bad(t_stack *stack);
t_stack_node	*stack_find_smallest(t_stack *stack);
t_stack_node	*stack_find_cheapest(t_stack *stack);
void			print_stack_op(t_stack *stack, char *fmt, char arg);

int				swap_stack(t_stack *stack, char arg);
void			swap_stacks(t_stack *stack_a, t_stack *stack_b);

int				push_stack(t_stack *stack_to, t_stack *stack_from);

int				rotate_stack(t_stack *stack, char arg);
int				rev_rotate_stack(t_stack *stack, char arg);
void			rotate_stacks(t_stack *stack_a, t_stack *stack_b);
void			rev_rotate_stacks(t_stack *stack_a, t_stack *stack_b);

#endif
