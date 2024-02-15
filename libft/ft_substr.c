/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:45:33 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/16 19:47:58 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static size_t	ft_shortest(size_t n1, size_t n2)
{
	if (n2 < n1)
		return (n2);
	return (n1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	d_len;

	if (s == 0x0)
		return (0x0);
	if (start >= (unsigned int)ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	d_len = ft_shortest(ft_strlen(s + start), len);
	d = malloc(sizeof(char) * (d_len + 1));
	if (!d)
		return (0x0);
	d[0] = '\0';
	ft_strlcpy(d, s + start, d_len + 1);
	return (d);
}

/*
int	main(void)
{
	char const	b1[] = "Toute la jungle est ma maison.";
	char const	b2[] = "";
	char const	*b3;
	char const	b4[] = "abc";

	b3 = 0x0;

	printf("%s\n", ft_substr(b1, 6, 10));

	printf("b1 case2 >>> %p\n", ft_substr(b1, 100, 10));
	printf("b1 case3 >>> %p\n", ft_substr(b1, 6, 0));
	printf("b2 >>> %p\n", ft_substr(b2, 6, 10));

	printf("b3 >>> %p\n", ft_substr(b3, 6, 10));

	printf("%s\n", ft_substr(b4, 1, 10));
	return (0);
}
*/
