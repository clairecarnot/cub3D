/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:57:35 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/11 17:49:44 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0x0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	char	dest[] = "Allo ici la Terre";
	char	src[] = "Bonjour les amis";
	char	dest2[] = "Allo ici la Terre";
	char	src2[] = "Bonjour les amis";

	//char	dest3[] = "";
	//char	src3[] = "Bonjour les amis";
	//char	dest4[] = "";
	//char	src4[] = "Bonjour les amis";

	char	dest5[] = "Allo ici la Terre";
	char	src5[] = "";
	char	dest6[] = "Allo ici la Terre";
	char	src6[] = "";

	ft_memcpy(dest, src, 7);
	memcpy(dest2, src2, 7);
	printf("%s\n%s\n%s\n%s\n", dest, src, dest2, src2);
	printf("\n");

	//ft_memcpy(dest3, src3, 7);
	//memcpy(dest4, src4, 7); overlap
	//printf("%s\n%s\n%s\n%s\n", dest3, src3, dest4, src4);
	//printf("\n");

	printf("%s\n%s\n%s\n%s\n", dest5, src5, dest6, src6);
	ft_memcpy(dest5, src5, 7);
	memcpy(dest6, src6, 7);
	printf("%s\n%s\n%s\n%s\n", dest5, src5, dest6, src6);
	return (0);
}*/
