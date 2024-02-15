/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:21:12 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/03 14:09:48 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	printf("14 > %d\n", ft_isascii(14));
	printf("-1 > %d\n", ft_isascii(-1));
	printf("10000 > %d\n", ft_isascii(10000));
	return (0);
}
*/
