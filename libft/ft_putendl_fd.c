/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:42:49 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 14:32:04 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

/*
int	main(void)
{
	char	i[] = "bla bla bla";
	int	fd;

	fd = open("test3.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("open failed");
		return (1);
	}
	ft_putendl_fd(i, fd);
	if (close(fd) == -1)
	{
		printf("close failed");
		return (1);
	}
	return (0);
}
*/
