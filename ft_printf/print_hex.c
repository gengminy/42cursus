/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:36:03 by knoh              #+#    #+#             */
/*   Updated: 2022/05/05 14:36:22 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex(char format, unsigned long val)
{
	unsigned long	cur;

	if (val / 16 == 0)
		cur = val;
	else
	{
		cur = (val % 16);
		put_hex(format, val / 16);
	}
	if (format == 'x')
		write(1, &"0123456789abcdef"[cur % 16], 1);
	else if (format == 'X')
		write(1, &"0123456789ABCDEF"[cur % 16], 1);
}

int	print_ptr(unsigned long hex_addr)
{
	write(1, "0x", 2);
	put_hex('x', hex_addr);
	return (get_numlen_base_unsigned(hex_addr, 16) + 2);
}

int	print_hex(char format, unsigned long val)
{
	put_hex(format, val);
	return (get_numlen_base_unsigned(val, 16));
}
