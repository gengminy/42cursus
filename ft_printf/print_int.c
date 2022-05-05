/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:36:08 by knoh              #+#    #+#             */
/*   Updated: 2022/05/05 14:36:23 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_unsigned_int(unsigned int val)
{
	char	cur_number;

	if (val / 10 == 0)
		cur_number = val + '0';
	else
	{
		cur_number = (val % 10) + '0';
		put_unsigned_int(val / 10);
	}
	write(1, &cur_number, 1);
}

int	print_int(int val)
{
	ft_putnbr_fd(val, 1);
	return (get_numlen_base_signed(val, 10));
}

int	print_unsigned_int(unsigned int val)
{
	put_unsigned_int(val);
	return (get_numlen_base_signed(val, 10));
}
