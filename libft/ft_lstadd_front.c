/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 08:37:04 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 11:58:15 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	t_list	new;
	t_list	p1;
	t_list	p2;
	t_list	p3;
	t_list	*lst;

	new.content = "Miam ";
	new.next = 0x0;
	p1.content = "et yohoho ";
	p2.content = "une bouteille ";
	p3.content = "de rhum";
	p1.next = &p2;
	p2.next = &p3;
	p3.next = 0x0;
	lst = &p1;
	ft_lstadd_front(&lst, &new);
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next; 
	}
	return (0);
}
*/
