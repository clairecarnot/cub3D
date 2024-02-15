/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:22:24 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/11 18:02:24 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (!dest && !src)
		return (0x0);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*
int	main(void)
{
	char	tab1[] = "abcdefghijklmno";
	char	tab1b[] = "abcdefghijklmno";
	char	tab2[] = "abcdefghijklmno";
	char	tab2b[] = "abcdefghijklmno";
	char	tab3[] = "abcdefghijklmno";
	char	tab3b[] = "abcdefghijklmno";
	char	tab4[] = "abcdefghijklmno";
	char	tab4b[] = "abcdefghijklmno";
	char	tab5[] = "abcdefghijklmno";
	char	tab5b[] = "abcdefghijklmno";
	//char	tab5b[] = "012345678901234";

	ft_memmove(tab1 + 5, tab1 + 2, sizeof(char) * 4);
	memmove(tab1b + 5, tab1b + 2, sizeof(char) * 4);
	printf("ft_memmove = %s\n   memmove = %s\n", tab1, tab1b);

	ft_memmove(tab2 + 1, tab2 + 12, sizeof(char) * 4);
	memmove(tab2b + 1, tab2b + 12, sizeof(char) * 4);
	printf("ft_memmove = %s\n   memmove = %s\n", tab2, tab2b);

	ft_memmove(tab3 + 1, tab3 + 2, sizeof(char) * 4);
	memmove(tab3b + 1, tab3b + 2, sizeof(char) * 4);
	printf("ft_memmove = %s\n   memmove = %s\n", tab3, tab3b);

	ft_memmove(tab4 + 12, tab4 + 1, sizeof(char) * 4);
	memmove(tab4b + 12, tab4b + 1, sizeof(char) * 4);
	printf("ft_memmove = %s\n   memmove = %s\n", tab4, tab4b);

	ft_memmove(tab5 + 3, tab5 + 3, sizeof(char) * 4);
	memmove(tab5b + 3, tab5b + 3, sizeof(char) * 4);
	printf("ft_memmove = %s\n   memmove = %s\n", tab5, tab5b);

	return (0);
}
*/
