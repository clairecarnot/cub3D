/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 08:41:05 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 12:15:41 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst == 0x0)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

/*
int	main(void)
{
	t_list	r1;
	t_list	r2;
	t_list	r3;
	t_list	new;
	t_list	*lst;

	r1.content = "chantons ";
	r2.content = "sous ";
	r3.content = "la pluie ";
	new.content = "gaiement";
	r1.next = &r2;
	r2.next = &r3;
	r3.next = 0x0;
	new.next = 0x0;
	lst = &r1;
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	lst = &r1;
	ft_lstadd_back(&lst, &new);
	lst = &r1;
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}*/
