/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 08:37:31 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 08:37:33 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*d;

	d = malloc(sizeof(t_list));
	if (!d)
		return (0x0);
	d->content = content;
	d->n = -1;
	d->next = 0x0;
	return (d);
}

/*
int	main(void)
{
	char	content[] = "et yohoho une bouteille de rhum";
	t_list	*o1;

	o1 = ft_lstnew(content);
	printf("%s\n", (char *)o1->content);
	printf("%p\n", o1->next);
	free(o1);
	return (0);
}
*/
