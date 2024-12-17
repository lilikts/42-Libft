/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:46:46 by lkloters          #+#    #+#             */
/*   Updated: 2024/10/23 18:28:00 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexadecimal_lowercase(unsigned long decimal)
{
	unsigned long	rest;
	int				length;
	int				check_error;

	length = 0;
	if (decimal >= 16)
	{
		check_error = hexadecimal_lowercase(decimal / 16);
		if (check_error == -1)
			return (-1);
		length += check_error;
	}
	rest = (decimal % 16);
	if (rest < 10)
		check_error = ft_putchar(rest + '0');
	else
		check_error = ft_putchar(rest - 10 + 'a');
	if (check_error == -1)
		return (-1);
	return (length + check_error);
}

int	hexadecimal_uppercase(unsigned long decimal)
{
	unsigned long	rest;
	int				length;
	int				check_error;

	length = 0;
	if (decimal >= 16)
	{
		check_error = hexadecimal_uppercase(decimal / 16);
		if (check_error == -1)
			return (-1);
		length += check_error;
	}
	rest = (decimal % 16);
	if (rest < 10)
		check_error = ft_putchar(rest + '0');
	else
		check_error = ft_putchar(rest - 10 + 'A');
	if (check_error == -1)
		return (-1);
	return (length + check_error);
}
