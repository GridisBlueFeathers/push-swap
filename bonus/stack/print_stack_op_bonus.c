/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_op_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:41:41 by svereten          #+#    #+#             */
/*   Updated: 2024/05/28 15:08:38 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack_bonus.h"
#include "ft_printf.h"

void	print_stack_op(t_stack *stack, char *fmt, char arg)
{
	if (arg == 'q')
		return ;
	ft_printf(fmt, stack->label);
}
