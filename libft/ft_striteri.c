/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:46:09 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/10 14:49:50 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*
void	g(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = 'p';
}
*/

void	ft_striteri(char *s, void (*g)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*g)(i, &s[i]);
		i++;
	}
}

/*
int	main(void)
{
	char	g1[] = "Viser la lune ca me fait pas peur";
	char	g2[] = "";
	char	*g3;

	g3 = 0x0;
	ft_striteri(g1, (*f));
	printf("%s\n", g1);

	ft_striteri(g2, (*f));
	printf("%s\n", g2);

	ft_striteri(g3, (*f));
	if (!g3)
		printf("tab nul");
	else	
		printf("%s\n", g3);
	return (0);
}
*/
