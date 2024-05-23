/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:42:14 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 10:11:26 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include "libft.h"

typedef struct s_stack_node
{
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	int					valid;
	int					value;
}	t_stack_node;

typedef struct s_stack
{
	size_t			len;
	t_stack_node	*head;
	//tail?
}	t_stack;

t_stack_node	*stack_init(char *arg);
t_stack	*stack_init_alt(void);
int		stack_append(t_stack *stack, char *arg);

void	swap_stack(t_stack *stack_a, char s);
void	swap_stacks(t_stack *stack_a, t_stack *stack_b);

#endif // !STACK_H
