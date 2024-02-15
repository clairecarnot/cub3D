/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:06:27 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 13:38:08 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		if (lst->content)
			(*del)(lst->content);
		free(lst);
	}
}

/*
int	main(void)
{
	t_list	s1;
	t_list	s2;
	t_list	s3;
	t_list	*lst;
	t_list	*lprint;

	s1.content = "phrase1";
	s2.content = "phrase2";
	s3.content = "phrase3";
	s1.next = &s2;
	s2.next = &s3;
	s3.next = 0x0;
	lst = &s2;
	lprint = &s1;
	while (lprint)
	{
		printf("%s\n", (char *)lprint->content);
		lprint = lprint->next;
	}
	ft_lstdelone(lst, (*del));
	lprint = &s1;
	while (lprint)
	{
		printf("%s\n", (char *)lprint->content);
		lprint = lprint->next;
	}
	return (0);
}*/
