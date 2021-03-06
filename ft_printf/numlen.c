/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:57 by knoh              #+#    #+#             */
/*   Updated: 2022/05/05 14:36:21 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_numlen_base_signed(long n, int base)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / base != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

int	get_numlen_base_unsigned(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n / base != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}
