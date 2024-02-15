/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:25:24 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 14:30:31 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

/*
int	main(void)
{
	int	fd;
	char	h1[] = "everything ain't nothing if i ain't got you";

	fd = open("test2.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("open failed");
		return (1);
	}
	ft_putstr_fd(h1, fd);
	ft_putstr_fd("\0", fd);
	if (close(fd) == -1)
	{
		printf("open failed");
		return (1);
	}
	return (0);
}
*/
