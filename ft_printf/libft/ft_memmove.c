/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:42:41 by knoh              #+#    #+#             */
/*   Updated: 2022/03/08 13:42:42 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;

	if (dst == src || len == 0)
		return (dst);
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	if (dst < src)
		while (len--)
			*uc_dst++ = *uc_src++;
	else
		while (len--)
			*(uc_dst + len) = *(uc_src + len);
	return (dst);
}
