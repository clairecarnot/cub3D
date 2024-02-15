/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:55:49 by ccarnot           #+#    #+#             */
/*   Updated: 2023/08/29 17:20:42 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(va_list ap)
{
	ft_putchar(va_arg(ap, int));
	return (1);
}

int	ft_print_str(va_list ap)
{
	char	*str;
	int		i;

	str = va_arg(ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_int(va_list ap)
{
	int	nb;

	nb = va_arg(ap, int);
	return (ft_putnbr(nb));
}

int	ft_print_uint(va_list ap)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	return (ft_putnbr_u(nb));
}
