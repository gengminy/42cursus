#include "ft_printf.h"

static void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

int print_char(char val)
{
	write(1, &val, 1);
	return (1);
}

int print_str(char *val)
{
	ft_putstr(val);
	return (ft_strlen(val));
}