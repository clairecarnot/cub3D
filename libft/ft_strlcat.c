/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ft_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:52:47 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 15:48:01 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	if (!dst && size == 0)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (len_src + size);
	while (i < (size - len_dst - 1) && src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/*
int	main(void)
{
	char	dst1[100] = "Vous avez dit";
	char	src1[] = " une tache de peinture ?";
	char	dst2[100] = "Vous avez dit";
	char	src2[] = " une tache de peinture ?";

	char	dst3[100] = "Vous avez dit";
	char	src3[] = " une tache de peinture ?";
	char	dst4[100] = "Vous avez dit";
	char	src4[] = " une tache de peinture ?";

	char	dst5[17] = "Vous avez dit";
	char	src5[] = " une tache de peinture ?";
	char	dst6[17] = "Vous avez dit";
	char	src6[] = " une tache de peinture ?";

	char	dst7[17] = "";
	char	src7[] = " une tache de peinture ?";
	char	dst8[17] = "";
	char	src8[] = " une tache de peinture ?";

	char	dst9[17] = "Vous avez dit";
	char	src9[] = "";
	char	dst10[17] = "Vous avez dit";
	char	src10[] = "";

	char	dst11[] = "Salut";
	char	src11[] = " une tache de peinture ?";
	char	dst12[] = "Salut";
	char	src12[] = " une tache de peinture ?";

	printf("%zu\n%zu\n", ft_strlcat(dst1, src1, 11), strlcat(dst2, src2, 11));
	printf("%s\n%s\n", dst1, dst2);

	printf("%zu\n%zu\n", ft_strlcat(dst3, src3, 0), strlcat(dst4, src4, 0));
	printf("%s\n%s\n", dst3, dst4);

	printf("%zu\n%zu\n", ft_strlcat(dst5, src5, 11), strlcat(dst6, src6, 11));
	printf("%s\n%s\n", dst5, dst6);

	printf("%zu\n%zu\n", ft_strlcat(dst7, src7, 11), strlcat(dst8, src8, 11));
	printf("%s\n%s\n", dst7, dst8);

	printf("%zu\n%zu\n", ft_strlcat(dst9, src9, 11), strlcat(dst10, src10, 11));
	printf("%s\n%s\n", dst9, dst10);

	printf("%zu\n%zu\n", ft_strlcat(dst11, src11, 11), strlcat(dst12, src12, 11));
	printf("%s\n%s\n", dst11, dst12);

	return (0);
}
*/
