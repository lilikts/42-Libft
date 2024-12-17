/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:43:57 by lkloters          #+#    #+#             */
/*   Updated: 2024/11/05 09:44:55 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	size_t	i;
	int		length;
	int		check_error;

	i = 0;
	length = 0;
	va_start(args, input);
	while (input[i] != '\0')
	{
		if (input[i] != '%')
			check_error = ft_putchar(input[i]);
		else
		{
			i++;
			check_error = format_check(input[i], args);
		}
		if (check_error == -1)
			return (va_end(args), -1);
		length += check_error;
		i++;
	}
	return (va_end(args), length);
}
// #include <stdio.h>

// int	main(void)
// {
// 	ft_printf("%d\n", ft_printf("%s\n", "abc"));
// 	printf("%d\n", printf("%s\n", "abc"));
// }
