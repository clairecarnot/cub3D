/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:52:25 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/10 14:15:34 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
}

/*
int	main(void)
{
	int	fd;

	fd = open("test4.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("open failed");
		return (1);
	}

	ft_putnbr_fd(42, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(-3, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n', fd);

	if (close(fd) == -1)
	{
		printf("close failed");
		return (1);
	}
	return (0);
}
*/
