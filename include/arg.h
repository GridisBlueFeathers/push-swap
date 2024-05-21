/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:56:57 by svereten          #+#    #+#             */
/*   Updated: 2024/05/21 12:26:55 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ARG_H
# define ARG_H

# include "stack.h"

int		validate_arg(char *arg, int *valid);
int		process_args(size_t args_amount, char **argv, t_stack *stack);

#endif
