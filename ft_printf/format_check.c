/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:59:16 by lkloters          #+#    #+#             */
/*   Updated: 2024/10/23 13:58:18 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pointer(unsigned long n)
{
	int	length;
	int	check_error;

	if (ft_putstr("0x") == -1)
		return (-1);
	length = 2;
	check_error = hexadecimal_lowercase(n);
	if (check_error == -1)
		return (-1);
	length += check_error;
	return (length);
}

int	format_check(const char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = ft_putchar(va_arg(args, int));
	else if (c == 's')
		length = ft_putstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		length = ft_putnbr(va_arg(args, int));
	else if (c == '%')
		length = ft_putchar('%');
	else if (c == 'u')
		length = ft_unsigned_putnbr(va_arg (args, unsigned int));
	else if (c == 'x')
		length = hexadecimal_lowercase(va_arg(args, unsigned int));
	else if (c == 'X')
		length = hexadecimal_uppercase(va_arg(args, unsigned int));
	else if (c == 'p')
		length = print_pointer(va_arg(args, unsigned long));
	return (length);
}
