/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:55:49 by ccarnot           #+#    #+#             */
/*   Updated: 2023/08/29 17:21:00 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hexa_low(va_list ap)
{
	unsigned int	n;

	n = va_arg (ap, unsigned int);
	return (ft_putnbr_hexa(n, "0123456789abcdef"));
}

int	ft_print_hexa_up(va_list ap)
{
	unsigned int	n;

	n = va_arg (ap, unsigned int);
	return (ft_putnbr_hexa(n, "0123456789ABCDEF"));
}

int	ft_print_pointer(va_list ap)
{
	unsigned long int	n;

	n = va_arg(ap, unsigned long int);
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + ft_putnbr_hexa_ulint(n, "0123456789abcdef"));
}
