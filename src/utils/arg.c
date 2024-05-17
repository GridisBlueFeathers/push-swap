/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:55:47 by svereten          #+#    #+#             */
/*   Updated: 2024/05/17 18:06:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	validate_arg(char *arg, int arg_num)
{
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if ((ft_intlen(arg_num) != arg_len)
		|| (!ft_isdigit(arg[0]) && arg_len == 1))
		return (0);
	return (1);
}

int	append_arg(int *arr, char *arg, int i)
{
	int	arg_num;
	int	j;

	arg_num = ft_atoi(arg);
	if (!validate_arg(arg, arg_num))
		return (0);
	j = 0;
	while (j < i - 1)
	{
		if (arr[j] == arg_num)
			return (0);
		j++;
	}
	arr[i - 1] = arg_num;
	return (1);
}
