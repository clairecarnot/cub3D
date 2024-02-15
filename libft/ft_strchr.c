/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:11:31 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/11 18:18:37 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}	
	return (0x0);
}

/*
int	main(void)
{
	const char	s[] = "Compagniiiiiie... marche !";

	printf("%s\n%s\n", strchr(s, 'i'), strchr(s, 'i'));
	printf("%s\n%s\n", strchr(s, 'k'), strchr(s, 'k'));
	printf("%s\n%s\n", strchr(s, 'm'), strchr(s, 'm'));
	printf("%s\n%s\n", strchr(s, '\0'), strchr(s, '\0'));
	printf("%s\n%s\n", strchr(s, 10000), strchr(s, 10000));
	printf("%s\n%s\n", strchr(s, -1), strchr(s, -1));
	return (0);
}
*/
