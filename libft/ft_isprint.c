/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:43:27 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/03 14:31:46 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	printf("27 >> %d\n", ft_isprint(27));
	printf("62 >> %d\n", ft_isprint(62));
	return (0);
}
*/
