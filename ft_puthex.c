/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirvine <nirvine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:36:19 by nirvine           #+#    #+#             */
/*   Updated: 2024/08/25 17:04:35 by nirvine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, int uppercase, int *len)
{
	const char	*hex;

	if (uppercase == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		if (ft_puthex(nbr / 16, uppercase, len) == -1)
			return (-1);
	}
	(*len)++;
	if (write(1, &(hex[nbr % 16]), 1) == -1)
		return (-1);
	return (*len);
}
