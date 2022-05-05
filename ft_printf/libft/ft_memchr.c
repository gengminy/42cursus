/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:42:35 by knoh              #+#    #+#             */
/*   Updated: 2022/03/08 13:42:36 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cmp;
	size_t			i;

	i = 0;
	cmp = (unsigned char *)s;
	while (i < n)
	{
		if (cmp[i] == (unsigned char)c)
			return (&cmp[i]);
		i++;
	}
	return (0);
}
