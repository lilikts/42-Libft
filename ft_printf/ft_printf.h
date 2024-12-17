/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:09:47 by lkloters          #+#    #+#             */
/*   Updated: 2024/10/22 15:28:19 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *input, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_unsigned_putnbr(unsigned int n);
int		ft_strlen2(const char *s);
int		num_length(int n);
int		ft_putnbr(int n);
int		hexadecimal_lowercase(unsigned long decimal);
int		hexadecimal_uppercase(unsigned long decimal);
int		format_check(const char c, va_list args);

#endif