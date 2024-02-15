/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:14:24 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/03 17:14:41 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)s)[n - 1] = c;
		n--;
	}
	return (s);
}

/*
int	main(void)
{
	char	s[] = "Bonjour les amis";

	ft_memset(s, 42, 4);
	printf("%s\n", s);
	return (0);
AUTRE METHODE :

	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)s)[i])
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
*/
