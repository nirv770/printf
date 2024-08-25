/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirvine <nirvine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:13:48 by nirvine          #+#    #+#             */
/*   Updated: 2024/08/25 16:59:23 by nirvine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;
	int	result;

	result = 0;
	if (str == 0)
	{
		result = write(1, "(null)", 6);
		if (result == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (str[len])
	{
		result = ft_putchar(str[len]);
		if (result == -1)
			return (-1);
		len++;
	}
	return (len);
}
