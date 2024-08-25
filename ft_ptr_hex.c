/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirvine <nirvine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:28:30 by nirvine          #+#    #+#             */
/*   Updated: 2024/08/25 16:54:46 by nirvine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_hex(unsigned long ptr, int *len)
{
	const char	*hex_digits;
	int			check;

	hex_digits = "0123456789abcdef";
	if (ptr >= 16)
	{
		if (ft_ptr_hex(ptr / 16, len) == -1)
			return (-1);
	}
	(*len)++;
	check = write(1, (&hex_digits[ptr % 16]), 1);
	if (check == -1)
		return (-1);
	return (*len);
}
