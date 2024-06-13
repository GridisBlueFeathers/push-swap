/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:07:31 by svereten          #+#    #+#             */
/*   Updated: 2024/06/13 17:15:41 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_validate_atoi(char *str, int	*num)
{
	int		str_num;
	char	*str_itoa;

	str_num = ft_atoi(str);
	str_itoa = ft_itoa(str_num);
	if (!str_itoa || ft_strncmp(str, str_itoa, ft_strlen(str)))
		return (ft_free_n_null((void **)&str_itoa), 0);
	*num = str_num;
	return (ft_free_n_null((void **)&str_itoa), 1);
}
