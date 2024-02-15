/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:35:49 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/10 12:21:12 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("open failed");
		return (1);
	}
	ft_putchar_fd('a', fd);
	if (close(fd) == - 1)
	{
		printf("close failed");
		return (1);
	}
	return (0);
}
*/
