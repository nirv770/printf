/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirvine <nirvine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:37:16 by nirvine           #+#    #+#             */
/*   Updated: 2024/08/25 17:04:56 by nirvine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int), &len));
	else if (format == 'p')
	{
		if (ft_putstr("0x") == -1
			|| ft_ptr_hex((unsigned long)va_arg(args, void *), &len) == -1)
			return (-1);
		return (2 + len);
	}
	else if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1, &len));
	else if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0, &len));
	else if (format == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int), &len));
	else if (format == '%')
		return (ft_putchar('%'));
	return (len);
}

static int	check(const char *str, va_list args, int *length, int *i)
{
	int	result;

	result = 0;
	if (str[(*i)] == '%')
	{
		result = formats(args, str[(*i) + 1]);
		if (result == -1)
			return (-1);
		(*length) += result;
		(*i) += 2;
	}
	else
	{
		result = ft_putchar(str[*i]);
		if (result == -1)
			return (-1);
		(*length) += result;
		(*i)++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (*(str + i))
	{
		if (check(str, args, &len, &i) == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (len);
}
