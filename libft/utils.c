/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:55:49 by ccarnot           #+#    #+#             */
/*   Updated: 2023/08/29 17:21:31 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int nb)
{
	long int	n;
	long int	cpy;
	int			written_chars;

	n = nb;
	written_chars = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		written_chars++;
		n *= (-1);
	}
	cpy = n;
	while (cpy > 9)
	{
		written_chars++;
		cpy /= 10;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (written_chars);
}

int	ft_putnbr_u(unsigned int n)
{
	unsigned int	cpy;
	int				written_chars;

	written_chars = 1;
	cpy = n;
	while (cpy > 9)
	{
		written_chars++;
		cpy /= 10;
	}
	if (n < 10)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (written_chars);
}

int	ft_putnbr_hexa(unsigned int n, char *base)
{
	unsigned int	cpy;
	int				written_chars;

	written_chars = 1;
	cpy = n;
	while (cpy > 15)
	{
		written_chars++;
		cpy /= 16;
	}
	if (n < 16)
		ft_putchar(base[n]);
	if (n > 15)
	{
		ft_putnbr_hexa(n / 16, base);
		ft_putchar(base[n % 16]);
	}
	return (written_chars);
}

int	ft_putnbr_hexa_ulint(unsigned long int n, char *base)
{
	unsigned long int	cpy;
	int					written_chars;

	written_chars = 1;
	cpy = n;
	while (cpy > 15)
	{
		written_chars++;
		cpy /= 16;
	}
	if (n < 16)
		ft_putchar(base[n]);
	if (n > 15)
	{
		ft_putnbr_hexa_ulint(n / 16, base);
		ft_putchar(base[n % 16]);
	}
	return (written_chars);
}
