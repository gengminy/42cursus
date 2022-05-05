/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:41:47 by knoh              #+#    #+#             */
/*   Updated: 2022/03/08 13:41:49 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					negative;
	unsigned long long	result;

	negative = 1;
	result = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (negative > 0 && result > 9223372036854775807llu)
		return (-1);
	if (negative < 0 && result > 9223372036854775808llu)
		return (0);
	return (negative * result);
}
