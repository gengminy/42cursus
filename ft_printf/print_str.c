/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:36:11 by knoh              #+#    #+#             */
/*   Updated: 2022/05/05 14:36:14 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *val)
{
	if (val == 0)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
	{
		ft_putstr_fd(val, 1);
		return (ft_strlen(val));
	}
}
