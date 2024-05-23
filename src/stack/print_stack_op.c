/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:41:41 by svereten          #+#    #+#             */
/*   Updated: 2024/05/23 11:49:51 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"
#include "ft_printf.h"

void	print_stack_op(t_stack *stack, char *fmt, char arg)
{
	if (arg == 'q')
		return ;
	ft_printf(fmt, stack->label);
}
