/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:59:07 by ccarnot           #+#    #+#             */
/*   Updated: 2024/01/04 17:56:29 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	printf("%d\n", strncmp("test\200", "test\0", 6));
	printf("%d\n%d\n", ft_strncmp("abc", "abd", -1), strncmp("abc", "abd", -1));
	printf("%d\n%d\n", ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
	printf("%d\n%d\n", ft_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
	printf("%d\n%d\n", ft_strncmp("abc", "abd", 2), strncmp("abc", "abd", 2));
	printf("%d\n%d\n", ft_strncmp("abc", "ab", 3), strncmp("abc", "ab", 3));
	printf("%d\n%d\n", ft_strncmp("", "abd", 2), strncmp("", "abd", 2));
	printf("%d\n%d\n", ft_strncmp("abc", "", 2), strncmp("abc", "", 2));
	printf("%d\n%d\n", ft_strncmp("abc", "", 0), strncmp("abc", "", 0));
	return (0);
}
*/
