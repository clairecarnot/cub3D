/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:54:35 by ccarnot           #+#    #+#             */
/*   Updated: 2023/12/06 11:12:33 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dest)
		return (0x0);
	i = 0;
	while (((char *)s)[i])
	{
		dest[i] = ((char *)s)[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int	main(void)
{
	const char	a[] = "Paroles que tous ces mots";

	printf("%s\n%s\n", ft_strdup(a), strdup(a));
	printf("%s\n%s\n", ft_strdup(""), strdup(""));
	return (0);
}
*/
