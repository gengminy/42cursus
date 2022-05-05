/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:48 by knoh              #+#    #+#             */
/*   Updated: 2022/05/05 14:36:16 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	print_var(const char format, va_list *ap)
{
	if (format == 'c')
		return (print_char(va_arg(*ap, int)));
	else if (format == 's')
		return (print_str(va_arg(*ap, char *)));
	else if (format == 'p')
		return (print_ptr(va_arg(*ap, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (print_int(va_arg(*ap, int)));
	else if (format == 'u')
		return (print_unsigned_int(va_arg(*ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (print_hex(format, va_arg(*ap, unsigned int)));
	else if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, str);
	ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ret += print_var(*str, &ap);
		}
		else
			ret += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (ret);
}
