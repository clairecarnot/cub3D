/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:57:17 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 10:31:57 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*beginning;

	if (!lst)
		return (0x0);
	newlist = ft_lstnew((*f)(lst->content));
	if (!newlist)
		return (0x0);
	beginning = newlist;
	lst = lst->next;
	while (lst)
	{
		newlist->next = ft_lstnew((*f)(lst->content));
		if (!newlist->next)
		{
			ft_lstclear(&beginning, (*del));
			return (0x0);
		}
		newlist = newlist->next;
		lst = lst->next;
	}
	return (beginning);
}
