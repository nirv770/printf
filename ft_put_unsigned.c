/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirvine <nirvine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:26:55 by nirvine           #+#    #+#             */
/*   Updated: 2024/08/25 17:04:44 by nirvine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int n, int *len)
{
	char	nbr;

	if (n / 10)
	{
		if (ft_put_unsigned(n / 10, len) == -1)
			return (-1);
	}
	nbr = '0' + (n % 10);
	if (ft_putchar(nbr) == -1)
		return (-1);
	(*len)++;
	return (*len);
}
