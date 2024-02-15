/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:01:45 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/05 12:06:44 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

/*
int     main(void)
{
        printf("%d\n%d\n", ft_tolower('m'), tolower('m'));
        printf("%d\n%d\n", ft_tolower('R'), tolower('R'));
        printf("%d\n%d\n", ft_tolower('('), tolower('('));
        printf("%d\n%d\n", ft_tolower('0'), tolower('0'));
        printf("%d\n%d\n", ft_tolower(1000), tolower(1000));
        printf("%d\n%d\n", ft_tolower(-1), tolower(-1));
        return (0);
}
*/
