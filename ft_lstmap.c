/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:03:27 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/13 23:03:27 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;
	t_list	*list;

	(void)del;
	node = lst->next;
	list = ft_lstnew(f(lst->content));
	head = list;
	while (node)
	{
		list->next = ft_lstnew(f(node->content));
		list = list->next;
		node = node->next;
	}
	return (head);
}
