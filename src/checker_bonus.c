/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:07:27 by svereten          #+#    #+#             */
/*   Updated: 2024/05/28 01:18:35 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	char *str;
	(void)argc;
	str = (char *)ft_calloc(42, sizeof(char));
	read(STDIN_FILENO, str, 41);
	ft_printf("%s %s", argv[1], str);
}
