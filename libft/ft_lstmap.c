/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:52:57 by jugwak            #+#    #+#             */
/*   Updated: 2022/07/15 21:57:20 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*node;

	if (!lst || !f)
		return (0);
	node = NULL;
	while (lst)
	{
		newnode = ft_lstnew((*f)(lst->content));
		if (!newnode)
		{
			ft_lstclear(&node, del);
			return (0);
		}
		ft_lstadd_back(&node, newnode);
		lst = lst->next;
		newnode = newnode->next;
	}
	return (node);
}
