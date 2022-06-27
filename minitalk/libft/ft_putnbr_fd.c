/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:42:49 by knoh              #+#    #+#             */
/*   Updated: 2022/03/08 13:42:49 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	cur_number;

	if (n < 0)
	{
		write(fd, "-", 1);
		cur_number = -(n % 10) + '0';
		if (n / 10 != 0)
			ft_putnbr_fd(-(n / 10), fd);
	}
	else if (n / 10 == 0)
	{
		cur_number = n + '0';
	}
	else
	{
		cur_number = (n % 10) + '0';
		ft_putnbr_fd(n / 10, fd);
	}
	write(fd, &cur_number, 1);
}
