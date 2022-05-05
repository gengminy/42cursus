/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:29:23 by knoh              #+#    #+#             */
/*   Updated: 2022/03/12 13:29:24 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_begin;
	t_list	*new_node;

	new_begin = 0;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_begin, del);
			return (0);
		}
		ft_lstadd_back(&new_begin, new_node);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (new_begin);
}
