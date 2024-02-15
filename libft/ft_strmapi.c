/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:54:46 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/10 11:13:42 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/*
char	f(unsigned int i, char c)
{
	if (i % 2 == 0)
		return ('p');
	return (c);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0x0);
	d = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!d)
		return (0x0);
	while (s[i])
	{
		d[i] = (*f)(i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*
int	main(void)
{
	char const	f1[] = " 123 Lalalala (hihi)";
	char const	f2[] = "";
	char const	*f3;
	char	*dst1;
	char	*dst2;
	char	*dst3;

	f3 = 0x0;
	dst1 = ft_strmapi(f1, (*f));
	if (!dst1)
		printf("dst est null");
	else
		printf("%s\n", dst1);
	dst2 = ft_strmapi(f2, (*f));
	if (!dst2)
		printf("dst est null");
	else
		printf("%s\n", dst2);
	dst3 = ft_strmapi(f3, (*f));
	if (!dst3)
		printf("dst est null");
	else
		printf("%s\n", dst3);
	return (0);
}
*/
