/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:28:50 by knoh              #+#    #+#             */
/*   Updated: 2022/03/12 13:28:52 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*tmp;

	cur = *lst;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = 0;
}
