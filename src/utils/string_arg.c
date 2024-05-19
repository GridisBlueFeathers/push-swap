/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:28:14 by svereten          #+#    #+#             */
/*   Updated: 2024/05/19 11:39:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	preprocess_string_arg(char *str_arg)
{
	int	i;

	i = 0;
	while (str_arg[i])
	{
		if (!(ft_isdigit(str_arg[i]) || str_arg[i] == ' ' || str_arg[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	process_string_arg(int *arr, char *str_arg)
{
	return (1);
}
