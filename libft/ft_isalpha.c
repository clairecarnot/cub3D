/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:39:41 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/03 13:48:12 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	printf("e >>> %d\n", ft_isalpha(101));
	printf("( >>> %d\n", ft_isalpha(40));
	printf("4 >>> %d\n", ft_isalpha(52));
	return (0);
}
*/
