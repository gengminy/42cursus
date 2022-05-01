#include "ft_printf.h"

static int	get_int_len(int n, int base)
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

int print_int(int val)
{
	ft_putnbr_fd(val, 1);
	return (get_int_len(val, 10));
}

int print_unsigned_int(unsigned int val)
{
	int	len;

	put_unsigned_int(val);
	len = 1;
	while (val / 10 != 0)
	{
		len++;
		val /= 10;
	}
	return (len);
}
