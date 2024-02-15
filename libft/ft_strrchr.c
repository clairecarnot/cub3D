/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:48:47 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/11 18:30:07 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i--;
	}
	return (0x0);
}

/*
int	main(void)
{
	char	s[] = "Cash rules everything around me";

	printf("%s\n%s\n", ft_strrchr(s, 'g'), strrchr(s, 'g'));
	printf("%s\n%s\n", ft_strrchr(s, 'a'), strrchr(s, 'a'));
	printf("%s\n%s\n", ft_strrchr(s, 'k'), strrchr(s, 'k'));
	printf("%s\n%s\n", ft_strrchr(s, '\0'), strrchr(s, '\0'));
	printf("%s\n%s\n", ft_strrchr(s, -1), strrchr(s, -1));
	printf("%s\n%s\n", ft_strrchr(s, 1000), strrchr(s, 1000));
	return (0);
}
*/
