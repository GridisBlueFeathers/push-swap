/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:37:21 by svereten          #+#    #+#             */
/*   Updated: 2024/05/27 20:41:28 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"

void	print_stack(t_stack *stack)
{
	t_stack_node	*cur;

	cur = stack->head;
	while (cur)
	{
		ft_printf("%d\n", cur->value);
		cur = cur->next;
	}
}

void print_stacks(t_stack *stack_a, t_stack *stack_b) {
  size_t max_len;
  size_t i;
  t_stack_node *cur_a;
  t_stack_node *cur_b;

  if (stack_a->len > stack_b->len)
    max_len = stack_a->len;
  else
    max_len = stack_b->len;
  i = 0;
  cur_a = stack_a->head;
  cur_b = stack_b->head;
  while (i < max_len) {
    if ((stack_a->len == max_len) || (i + stack_a->len >= max_len && cur_a)) {
      ft_printf("%d ", cur_a->value);
      cur_a = cur_a->next;
    } else
      ft_printf("  ");
    if ((stack_b->len == max_len) || (i + stack_b->len >= max_len && cur_b)) {
      ft_printf("%d\n", cur_b->value);
      cur_b = cur_b->next;
    } else
      ft_printf(" \n");
    i++;
  }
}

void print_stacks_util(t_stack *stack_a, t_stack *stack_b) {
  size_t max_len;
  size_t i;
  t_stack_node *cur_a;
  t_stack_node *cur_b;

  if (stack_a->len > stack_b->len)
    max_len = stack_a->len;
  else
    max_len = stack_b->len;
  i = 0;
  cur_a = stack_a->head;
  cur_b = stack_b->head;
  while (i < max_len) {
    if ((stack_a->len == max_len) || (i + stack_a->len >= max_len && cur_a)) {
      ft_printf("%d ", cur_a->value);
      cur_a = cur_a->next;
    } else
      ft_printf("  ");
    if ((stack_b->len == max_len) || (i + stack_b->len >= max_len && cur_b)) {
      ft_printf("%d\n", cur_b->top_cost);
      cur_b = cur_b->next;
    } else
      ft_printf(" \n");
    i++;
  }
}

