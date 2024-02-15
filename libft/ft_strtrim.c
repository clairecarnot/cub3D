/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:44:11 by ccarnot           #+#    #+#             */
/*   Updated: 2023/12/11 16:14:26 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*d;

	i = 0;
	if (!s1 || !set)
		return (0x0);
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && ft_isset(s1[j], set))
		j--;
	d = malloc(sizeof(char) * (j - i + 2));
	if (!d)
		return (0x0);
	k = 0;
	while (i <= j)
	{
		d[k] = s1[i];
		k++;
		i++;
	}
	d[k] = '\0';
	return (d);
}

/*
int	main(void)
{
	char const	d1[] = "?,,,He bonjour ??monsieur ,du Corbeau??";
//	char const	*d1;
	char const	d2[] = "He bonjour mo?ns,ieur du Corbe,au??";
	char const	d3[] = "?He bonjour mo,,,nsieur du Corbeau";
	char const	d4[] = "He bonjour monsieu?r du Corbeau";
	char const	d5[] = "";
	char const	d6[] = "?,,,He bonjour mons??ieur du Corbeau??";
	char const	set1[] = "?,";
	char const	set2[] = "";
	//char const	*set2;

//	set2 = 0x0;
//	d1 = 0x0;
	printf("%s\n", ft_strtrim(d1, set1));
	printf("%s\n", ft_strtrim(d2, set1));
	printf("%s\n", ft_strtrim(d3, set1));
	printf("%s\n", ft_strtrim(d4, set1));
	printf("%s\n", ft_strtrim(d5, set1));
	printf("%s\n", ft_strtrim(d6, set2));
	return (0);
}
*/
