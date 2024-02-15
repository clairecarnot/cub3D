/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 08:38:09 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 08:38:11 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
int	main(void)
{
	t_list	q1;
	t_list	q2;
	t_list	q3;
	t_list	*lst;

	lst = &q1;
	q1.content ="et un";
	q2.content ="et deux";
	q3.content ="et trois";
	q1.next = &q2;
	q2.next = &q3;
	q3.next = 0x0;
	printf("%d\n", ft_lstsize(lst));
	return (0);
}*/
