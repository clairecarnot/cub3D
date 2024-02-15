/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 08:37:48 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 11:24:36 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

/*
int	main(void)
{
	t_list	r1;
	t_list	r2;
	t_list	r3;
	t_list	*lst;

	r1.content = "blabla";
	r2.content = "blibli";
	r3.content = "blublu";
	r1.next = &r2;
	r2.next = &r3;
	r3.next = 0x0;;
	lst = &r1;
	printf("%s\n", (char *)ft_lstlast(lst)->content);
	return (0);
}*/
