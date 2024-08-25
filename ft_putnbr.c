/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirvine <nirvine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:31:46 by nirvine           #+#    #+#             */
/*   Updated: 2024/08/25 17:04:29 by nirvine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		*len += 11;
		return (*len);
	}
	else
	{
		if (n < 0)
		{
			if (ft_putchar('-') == -1)
				return (-1);
			n = n * -1;
			(*len)++;
		}
		if (n > 9)
			if (ft_putnbr(n / 10, len) == -1)
				return (-1);
		if (ft_putchar((n % 10) + '0') == -1)
			return (-1);
		(*len)++;
	}
	return (*len);
}
