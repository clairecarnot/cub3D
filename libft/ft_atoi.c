/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:27:40 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/05 18:56:01 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	n;

	n = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign *= (-1);
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	return (n * sign);
}

/*
int	main(void)
{
	printf("%d\n%d\n", ft_atoi("1234"), atoi("1234"));
	printf("%d\n%d\n", ft_atoi("      	-1234"), atoi("            -1234"));
	printf("%d\n%d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
	printf("%d\n%d\n", ft_atoi("2147483647"), atoi("2147483647"));
	printf("%d\n%d\n", ft_atoi(""), atoi(""));
	printf("%d\n%d\n", ft_atoi("++-1234"), atoi("++-1234"));
	return (0);
}
*/
