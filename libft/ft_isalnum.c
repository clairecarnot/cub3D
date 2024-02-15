/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:39:41 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/03 12:35:05 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123) || (c > 47 && c < 58))
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	printf("e >>> %d\n", ft_isalnum(101));
	printf("( >>> %d\n", ft_isalnum(40));
	printf("4 >>> %d\n", ft_isalnum(52));
	return (0);
}
*/
