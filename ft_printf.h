/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirvine <nirvine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:50:06 by nirvine          #+#    #+#             */
/*   Updated: 2024/08/25 16:54:02 by nirvine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putstr(char *str);
int	ft_putchar(char x);
int	ft_putnbr(int n, int *len);
int	ft_printf(const char *str, ...);
int	ft_ptr_hex(unsigned long ptr, int *len);
int	ft_put_unsigned(unsigned int n, int *len);
int	ft_puthex(unsigned int nbr, int uppercase, int *len);

#endif
