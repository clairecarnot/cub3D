/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:05:39 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/11 17:30:30 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *) s1;
	m2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (m1[i] != m2[i])
			return (m1[i] - m2[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char 	p1[] = "abc";
	char	p2[] = "ab";

	char 	p3[] = "abc";
	char	p4[] = "abd";

	char 	p5[] = "abc";
	char	p6[] = "ab";

	char 	p7[] = "";
	char	p8[] = "abc";

	char 	p9[] = "abc";
	char	p10[] = "";

	printf("%d\n%d\n", ft_memcmp(p1, p2, 3), memcmp(p1, p2, 3));
	printf("%d\n%d\n", ft_memcmp(p3, p4, 2), memcmp(p3, p4, 2));
	printf("%d\n%d\n", ft_memcmp(p5, p6, 3), memcmp(p5, p6, 3));
	printf("%d\n%d\n", ft_memcmp(p7, p8, 3), memcmp(p7, p8, 3));
	printf("%d\n%d\n", ft_memcmp(p9, p10, 3), memcmp(p9, p10, 3));
	return (0);
}
*/
