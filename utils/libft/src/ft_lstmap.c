/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:17:03 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/14 19:29:11 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*lst_head;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	lst_head = new_lst;
	lst = lst->next;
	while (lst)
	{	
		new_lst->next = ft_lstnew(f(lst->content));
		new_lst = new_lst->next;
		if (!new_lst)
		{
			del(new_lst);
			free(new_lst);
		}
		lst = lst->next;
	}
	return (lst_head);
}
