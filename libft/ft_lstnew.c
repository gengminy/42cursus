/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:29:32 by knoh              #+#    #+#             */
/*   Updated: 2022/03/12 13:29:32 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}
