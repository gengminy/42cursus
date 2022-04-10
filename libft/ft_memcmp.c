/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:42:37 by knoh              #+#    #+#             */
/*   Updated: 2022/03/08 13:42:38 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;
	size_t			i;

	i = 0;
	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	while (i < n)
	{
		if (uc1[i] != uc2[i])
			return (uc1[i] - uc2[i]);
		i++;
	}
	return (0);
}
