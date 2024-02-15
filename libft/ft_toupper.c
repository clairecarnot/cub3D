/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:50:43 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/05 12:02:53 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}

/*
int	main(void)
{
	printf("%d\n%d\n", ft_toupper('m'), toupper('m'));
	printf("%d\n%d\n", ft_toupper('R'), toupper('R'));
	printf("%d\n%d\n", ft_toupper('('), toupper('('));
	printf("%d\n%d\n", ft_toupper('0'), toupper('0'));
	printf("%d\n%d\n", ft_toupper(1000), toupper(1000));
	printf("%d\n%d\n", ft_toupper(-1), toupper(-1));
	return (0);
}
*/
