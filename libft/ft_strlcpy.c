/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:24:44 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/11 11:13:39 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <bsd/string.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
int	main(void)
{
	char dst1[20];
	char src1[] = "Beau temps pour la saison";
	char dst2[20];
	char src2[] = "Beau temps pour la saison";

	char dst3[20];
	char src3[] = "";
	char dst4[20];
	char src4[] = "";

	char dst5[20];
	char *src5;
	char dst6[20];
	char *src6;

	src5 = 0x0;
	src6 = 0x0;

	printf("%zu\n %zu\n", ft_strlcpy(dst1, src1, 10), strlcpy(dst2, src2, 10));
	printf("%s\n %s\n", dst1, dst2);

	printf("%zu\n %zu\n", ft_strlcpy(dst3, src3, 10), strlcpy(dst4, src4, 10));
	printf("%s\n %s\n", dst3, dst4);

	printf("%zu\n %zu\n", ft_strlcpy(dst5, src5, 10), strlcpy(dst6, src6, 10));
	printf("%s\n %s\n", dst5, dst6);

	return (0);
}
*/
