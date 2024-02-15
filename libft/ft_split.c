/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:44:50 by ccarnot           #+#    #+#             */
/*   Updated: 2024/01/23 17:29:28 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_nstr(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
			n++;
		while (s[i] && s[i] != c && s[i])
			i++;
		if (s[i])
			i++;
	}
	return (n);
}

static int	ft_strlenc(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*ft_free(char **d)
{
	int	i;

	i = 0;
	while (d[i])
		free(d[i++]);
	free(d);
	return (0x0);
}

char	**ft_split(char const *s, char c)
{
	int		nstr;
	int		i;
	char	**d;

	if (!s)
		return (0x0);
	nstr = ft_nstr(s, c);
	d = malloc(sizeof(char *) * (nstr + 1));
	if (!d)
		return (0x0);
	d[nstr] = 0;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			d[i] = ft_substr(s, 0, ft_strlenc(s, c));
			if (!d[i++])
				return (ft_free(d));
			s += ft_strlenc(s, c);
		}
		else
			s++;
	}
	return (d);
}

/*
int	main(void)
{
	char	**dest1;
	char const	*e1 = 0x0;
	char	c1;
	int	i;

	i = 0;
	c1 = '?';
	dest1 = ft_split(e1, c1);
	if (dest1 == 0x0)
		printf("dest == NULL\n");
	else 
	{
		while (dest1[i])
			printf("%s\n", dest1[i++]);
	}
	return (0);
}

int	main(void)
{
	char	**dest1;
	char	**dest2;
	char	**dest3;
	char	**dest4;
	char	**dest5;
	char	**dest6;
	char	**dest7;
	char	e1[] = "???Le meilleur?repos est celui qui suit le travail????";
	char	e2[] = "?Le meilleur?repos est celui qui suit le travail";
	char	e3[] = "Le meilleur?repos est celui qui suit le travail?";
	char	e4[] = "Le meilleur?repos est celui ?qui suit le travail";
	char	e5[] = "";
	char	e6[] = "Le meilleur?repos est celui ?qui suit le travail";
	char	e7[] = "Le meilleur repos est celui qui suit le travail";
	char	c1;
	char	c2;
	int	i;
	
	i = 0;
	c1 = '?';
	c2 = '\0';
	dest1 = ft_split(e1, c1);
	dest2 = ft_split(e2, c1);
	dest3 = ft_split(e3, c1);
	dest4 = ft_split(e4, c1);
	dest5 = ft_split(e5, c1);
	dest6 = ft_split(e6, c2);
	dest7 = ft_split(e7, c1);
	while (dest1[i])
		printf("%s\n", dest1[i++]);
	i = 0;
	while (dest1[i])
		free(dest1[i++]);
	free(dest1);
	i = 0;
	while (dest2[i])
		printf("%s\n", dest2[i++]);
	i = 0;
	while (dest3[i])
		printf("%s\n", dest3[i++]);
	i = 0;
	while (dest4[i])
		printf("%s\n", dest4[i++]);
	i = 0;
	while (dest5[i])
		printf("%s\n", dest5[i++]);
	i = 0;
	while (dest6[i])
		printf("%s\n", dest6[i++]);
	i = 0;
	while (dest7[i])
		printf("%s\n", dest7[i++]);
	return (0);
}
*/
