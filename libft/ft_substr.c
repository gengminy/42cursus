/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:43:39 by knoh              #+#    #+#             */
/*   Updated: 2022/03/08 13:43:40 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (s_len < len)
		len = s_len;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	ft_memcpy(result, s + start, len);
	result[len] = 0;
	return (result);
}
