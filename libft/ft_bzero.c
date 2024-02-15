/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:42:07 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/04 10:34:59 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <strings.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)s)[n - 1] = '\0';
		n--;
	}
}

/*
int	main(void)
{
	char	s[] = "Bonjour les amigos";
	int	i;

	ft_bzero(s, 5);
	//bzero(s, 1);
	i = 0;
	while (i < 18)
	{
		printf("%c", s[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
