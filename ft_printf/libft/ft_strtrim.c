/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:43:37 by knoh              #+#    #+#             */
/*   Updated: 2022/03/08 13:43:38 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	char	*p;

	p = 0;
	if (s1 && set)
	{
		front = 0;
		back = ft_strlen(s1);
		while (s1[front] && ft_strchr(set, s1[front]))
			front++;
		while (s1[back - 1] && ft_strchr(set, s1[back - 1]) && front < back)
			back--;
		p = (char *)malloc(back - front + 1);
		if (p)
			ft_strlcpy(p, &s1[front], back - front + 1);
	}
	return (p);
}
