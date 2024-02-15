/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:28:26 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/10 17:14:18 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0x0);
}

/*
int	main(void)
{
	char	p[] = "Non mais allo quoi";
	int	tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("%s\n%s\n", (char *)ft_memchr(p, 'a', 8), (char *)memchr(p, 'a', 8));
	printf("%s\n%s\n", (char *)ft_memchr(p, 'a', 3), (char *)memchr(p, 'a', 3));
	printf("%s\n%s\n", (char *)ft_memchr(p, '\0', 40), (char *)memchr(p, '\0', 40));
	printf("%s\n%s\n", (char *)ft_memchr(p, -1, 3), (char *)memchr(p, -1, 3));
	printf("%s\n%s\n", (char *)ft_memchr(p, 'a', 0), (char *)memchr(p, 'a', 0));
	printf("%s\n%s\n", (char *)ft_memchr(tab, -1, 7), (char *)memchr(tab, -1, 7));
	printf("%s\n%s\n", (char *)ft_memchr(tab, 49, 2), (char *)memchr(tab, 49, 2));
	printf("%s\n%s\n", (char *)ft_memchr(tab, 49, 1), (char *)memchr(tab, 49, 1));
	return (0);
}
*/
