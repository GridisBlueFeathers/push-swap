/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:42:14 by svereten          #+#    #+#             */
/*   Updated: 2024/05/21 11:57:04 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack_node
{
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	int					*len;
	int					valid;
	int					value;
}	t_stack_node;

t_stack_node	*stack_init(char *arg);
t_stack_node	*stack_append(t_stack_node **start, char *arg);

void	swap_stack(t_stack_node **stack, char s);

#endif // !STACK_H
