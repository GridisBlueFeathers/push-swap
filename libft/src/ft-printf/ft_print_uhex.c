/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:05:26 by svereten          #+#    #+#             */
/*   Updated: 2024/04/23 16:51:02 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_uhex(unsigned long n, char fmt)
{
	int		bytes_written;
	int		res;
	char	*base;

	base = "0123456789abcdef";
	if (fmt == 'X')
		base = "0123456789ABCDEF";
	res = 0;
	if (n < 16)
	{
		bytes_written = ft_print_char(base[n]);
		return (bytes_written);
	}
	bytes_written = ft_print_uhex(n / 16, fmt);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	bytes_written = ft_print_uhex(n % 16, fmt);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	return (res);
}
