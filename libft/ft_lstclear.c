/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:35:17 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/15 13:58:08 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*tmp;

	if (lst && del)
	{
		ptr = *lst;
		while (ptr)
		{
			tmp = ptr->next;
			(*del)(ptr->content);
			free(ptr);
			ptr = tmp;
		}
		*lst = 0x0;
	}
}
