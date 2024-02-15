/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:43:54 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 15:59:06 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	int		bytes;

	bytes = (int)(nmemb * size);
	if (size)
	{
		if ((size_t)bytes / size != nmemb)
			return (0x0);
	}
	dest = malloc(nmemb * size);
	if (!dest)
		return (0x0);
	ft_bzero(dest, nmemb * size);
	return (dest);
}

/*
int	main(void)
{
	char	*dest;
	char	*destb;
	char	*dest2;
	char	*dest2b;

	dest = ft_calloc(sizeof(char), 4);
	destb = calloc(sizeof(char), 4);
	dest2 = ft_calloc(30, 1);
	dest2b = calloc(30, 1);
	printf("%p\n", dest);
	printf("%p\n", destb);
	printf("%p\n", dest2);
	printf("%p\n", dest2b);
	free(dest);
	free(destb);
	free(dest2);
	free(dest2b);
	return (0);
}
*/
