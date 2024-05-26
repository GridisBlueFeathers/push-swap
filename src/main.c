/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:26:15 by svereten          #+#    #+#             */
/*   Updated: 2024/05/26 11:03:18 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "algo.h"
#include "arg.h"
#include "ft_printf.h"
#include "libft.h"
#include "stack.h"

t_stack_node *stack_at(t_stack *stack, int index)
{
	int i;
	t_stack_node *cur;

	if (!stack || !stack->head)
		return (NULL);
	i = 0;
	cur = stack->head;
	while (i < index && cur)
	{
		cur = cur->next;
		i++;
	}
	return (cur);
}

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
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
	while (i < max_len)
	{
		if ((stack_a->len == max_len)
			|| (i + stack_a->len >= max_len && cur_a))
		{
			ft_printf("%d ", cur_a->value);
			cur_a = cur_a->next;
		}
		else
			ft_printf("  ");
		if ((stack_b->len == max_len)
			|| (i + stack_b->len >= max_len && cur_b))
		{
			ft_printf("%d\n", cur_b->value);
			cur_b = cur_b->next;
		}
		else
			ft_printf(" \n");
		i++;
	}
}

void print_stacks_util(t_stack *stack_a, t_stack *stack_b)
{
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
	while (i < max_len)
	{
		if ((stack_a->len == max_len)
			|| (i + stack_a->len >= max_len && cur_a))
		{
			ft_printf("%d ", cur_a->value);
			cur_a = cur_a->next;
		}
		else
			ft_printf("  ");
		if ((stack_b->len == max_len)
			|| (i + stack_b->len >= max_len && cur_b))
		{
			ft_printf("%d\n", cur_b->below->value);
			cur_b = cur_b->next;
		}
		else
			ft_printf(" \n");
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc == 1)
		return (0);
	stack_a = stack_init('a');
	stack_b = stack_init('b');

	if (!stack_a || !stack_b)
		return (stack_free(stack_a), stack_free(stack_b), ft_printf("Error\n"), 1);

	if (!process_args(argc, argv, stack_a))
		return (stack_free(stack_a), stack_free(stack_b), ft_printf("Error\n"), 1);

	algo(stack_a, stack_b);

	/*print_stacks(stack_a, stack_b);
	printf("\n");
	print_stacks_util(stack_a, stack_b);
	printf("\n");
	print_stack(stack_a);*/


	return (stack_free(stack_a), stack_free(stack_b), 0);
	return (0);
}
