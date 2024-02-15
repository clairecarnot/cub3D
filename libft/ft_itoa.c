/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:45:09 by ccarnot           #+#    #+#             */
/*   Updated: 2024/01/30 09:38:39 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_countn(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*d;
	int			i;

	nb = n;
	d = malloc(sizeof(char) * (ft_countn(n) + 1));
	if (!d)
		return (0x0);
	if (n < 0)
		nb = -nb;
	i = ft_countn(n);
	d[i--] = '\0';
	while (i >= 0)
	{
		d[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	if (n < 0)
		d[0] = '-';
	return (d);
}

/*
int	main(void)
{
	printf("%s\n", ft_itoa(5));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(542));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	return (0);
}
*/
