/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:33:04 by lkloters          #+#    #+#             */
/*   Updated: 2024/10/28 18:19:41 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	num;
	int		length;
	int		check_error;

	num = (long) n;
	length = 0;
	if (num < 0)
	{
		check_error = ft_putchar('-');
		if (check_error == -1)
			return (-1);
		length += check_error;
		num = -num;
	}
	if (num >= 10)
	{
		check_error = ft_putnbr(num / 10);
		if (check_error == -1)
			return (-1);
		length += check_error;
	}
	check_error = ft_putchar((num % 10) + '0');
	if (check_error == -1)
		return (-1);
	return (length + check_error);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	long	num;
	int		length;
	int		check_error;

	num = (long) n;
	length = 0;
	if (num >= 10)
	{
		check_error = ft_putnbr(num / 10);
		if (check_error == -1)
			return (-1);
		length += check_error;
	}
	check_error = ft_putchar((num % 10) + '0');
	if (check_error == -1)
		return (-1);
	return (length + check_error);
}
