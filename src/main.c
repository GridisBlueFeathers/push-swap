/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:26:15 by svereten          #+#    #+#             */
/*   Updated: 2024/05/17 18:04:54 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"
#include "arg.h"

int	main(int argc, char **argv)
{
	int	i;
	int	*arr;

	i = 1;
	arr = (int *)ft_calloc(argc - 1, sizeof(int));
	if (!arr)
		return (ft_printf("Error\n"), 1);
	while (i < argc)
	{
		if (!append_arg(arr, argv[i], i))
			return (ft_free_n_null((void *)&arr), ft_printf("Error\n"), 1);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}
