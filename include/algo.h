/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:41:53 by svereten          #+#    #+#             */
/*   Updated: 2024/05/27 20:31:45 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "stack.h"

int		algo(t_stack *stack_a, t_stack *stack_b);

void	algo_case_two(t_stack *stack_a);
void	algo_case_three(t_stack *stack_a);

void	algo_top_node(t_stack *stack, t_stack_node *node);

void	algo_calc_up_up(t_stack_node *node);
void	algo_calc_down_down(t_stack *a, t_stack *b, t_stack_node *node);
void	algo_calc_up_down(t_stack *b, t_stack_node *node);
void	algo_calc_down_up(t_stack *a, t_stack_node *node);

void	algo_top_up_up(t_stack *a, t_stack *b, t_stack_node *c);
void	algo_top_down_down(t_stack *a, t_stack *b, t_stack_node *c);
void	algo_top_up_down(t_stack *a, t_stack *b, t_stack_node *c);
void	algo_top_down_up(t_stack *a, t_stack *b, t_stack_node *c);

#endif
