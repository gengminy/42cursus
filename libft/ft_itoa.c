/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:42:33 by knoh              #+#    #+#             */
/*   Updated: 2022/03/08 13:42:34 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len(int n)
{
	int	count;

	if (n < 0)
		count = 2;
	else
		count = 1;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		front;
	int		back;
	char	*result;

	front = 0;
	back = get_len(n);
	result = (char *)malloc(back + 1);
	if (!result)
		return (0);
	if (n < 0)
		result[front++] = '-';
	result[back--] = 0;
	while (front <= back)
	{
		if (n < 0)
			result[back--] = -(n % 10) + '0';
		else
			result[back--] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
