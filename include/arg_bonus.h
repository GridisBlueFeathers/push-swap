/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:56:57 by svereten          #+#    #+#             */
/*   Updated: 2024/05/28 14:40:23 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ARG_BONUS_H
# define ARG_BONUS_H

# include "stack_bonus.h"

int	validate_arg(t_stack *stack, char *arg, int *valid);
int	process_args(size_t args_amount, char **argv, t_stack *stack);

#endif
