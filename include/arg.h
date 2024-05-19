/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:56:57 by svereten          #+#    #+#             */
/*   Updated: 2024/05/19 14:14:33 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ARG_H
# define ARG_H

# include "stack.h"

int				validate_arg(char *arg, int *valid);
t_stack_node	*process_args(int args_amount, char **argv);

#endif
