/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:55:49 by ccarnot           #+#    #+#             */
/*   Updated: 2023/08/29 17:20:01 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_readarg(va_list ap, char c)
{
	int	written_chars;

	written_chars = 0;
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (c == 'c')
		written_chars = ft_print_char(ap);
	if (c == 's')
		written_chars = ft_print_str(ap);
	if (c == 'p')
		written_chars = ft_print_pointer(ap);
	if (c == 'd' || c == 'i')
		written_chars = ft_print_int(ap);
	if (c == 'u')
		written_chars = ft_print_uint(ap);
	if (c == 'x')
		written_chars = ft_print_hexa_low(ap);
	if (c == 'X')
		written_chars = ft_print_hexa_up(ap);
	return (written_chars);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		chars_written;

	if (!s)
		return (-1);
	chars_written = 0;
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			chars_written++;
		}
		else
			chars_written += ft_readarg(ap, s[++i]);
		i++;
	}
	va_end(ap);
	return (chars_written);
}
