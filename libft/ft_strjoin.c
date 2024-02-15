/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:44:43 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/10 09:50:37 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0x0);
	dest = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (0x0);
	i = 0;
	while (((char *)s1)[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (((char *)s2)[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char const	c1[] = "Joyeux ";
	char const	c2[] = "anniversaire";
	char const	c3[] = "";
	char const	c4[] = "anniversaire";
	char const	c5[] = "Joyeux ";
	char const	c6[] = "";
	char const	c7[] = "";
	char const	c8[] = "";
	char const	*c9;
	char const	*c10;
	char const	c11[] = "Joyeux ";
	char const	*c12;

	c9 = 0x0;
	c10 = 0x0;
	c12 = 0x0;
	printf("%s\n", ft_strjoin(c1, c2));
	printf("%s\n", ft_strjoin(c3, c4));
	printf("%s\n", ft_strjoin(c5, c6));
	printf("%s\n", ft_strjoin(c7, c8));
	printf("%p\n", ft_strjoin(c9, c10));
	printf("%p\n", ft_strjoin(c11, c12));
	return (0);
}
*/
