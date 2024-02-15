/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:05:18 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/12 11:56:42 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len && big[i] && little[j])
	{
		j = 0;
		while (i + j < len && big[i + j] && big[i + j] == little[j])
			j++;
		if (little[j])
			i++;
	}
	if (little[j])
		return (0x0);
	return ((char *)&big[i]);
}

/*
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i + j < len && big[i + j] == little[j])
				j++;
			if (j == ft_strlen(little))
				return (&(((char *)big)[i]));
		}
		i++;
	}
	return (0x0);
}

int	main(void)
{
	const char	big[] = "chapi et chapo sont dans un bateau";
	const char	little[] = "chapo";
	const char	big2[] = "chapi et chapo sont dans un bateau";
	const char	little2[] = "";
	const char	big3[] = "";
	const char	little3[] = "chapo";
	const char	big4[] = "chapi et chapo sont dans un bateau";
	const char	little4[] = "chapo";
	const char	big5[] = "chapi et chapo sont dans un bateau";
	const char	little5[] = "chapo";

	printf("%s\n%s\n", ft_strnstr(big, little, 25), strnstr(big, little, 25));
	printf("%s\n%s\n", ft_strnstr(big2, little2, 25), strnstr(big2, little2, 25));
	printf("%s\n%s\n", ft_strnstr(big3, little3, 25), strnstr(big3, little3, 25));
	printf("%s\n%s\n", ft_strnstr(big3, little4, 2), strnstr(big4, little3, 2));
	printf("%s\n%s\n", ft_strnstr(big3, little5, 0), strnstr(big5, little3, 0));
	return (0);
}
*/
