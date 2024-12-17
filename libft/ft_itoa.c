/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:10:04 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/10 09:57:49 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	string_length(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static void	magic(char *str, int n, int length)
{
	while (n > 0)
	{
		str[length] = n % 10 + '0';
		n = n / 10;
		length--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	length = string_length(n);
	str = malloc(length + sign + 1);
	if (str == 0)
		return (0);
	str[length + sign] = '\0';
	if (sign == 1)
		str[0] = '-';
	magic(str, n, length + sign -1);
	return (str);
}
