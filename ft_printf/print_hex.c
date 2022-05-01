#include "ft_printf.h"

static void	put_unsigned_long(unsigned long hex_addr, int len)
{
	unsigned long	cur;

	if (hex_addr / 16 == 0 && len == 1)
		cur = hex_addr;
	else
	{
		cur = (hex_addr % 16);
		put_unsigned_long(hex_addr / 16, len - 1);
	}
	write(1, &"0123456789abcdef"[cur % 16], 1);
}

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

static void	put_hex_int(char format, int val)
{
	int	cur;

	if (val < 0)
	{
		write(1, "-", 1);
		cur = -(val % 16);
		if (val / 16 != 0)
			put_hex_int(format, -(val / 16));
	}
	else if (val / 16 == 0)
		cur = val;
	else
	{
		cur = (val % 16);
		put_hex_int(format, val / 16);
	}
	if (format == 'x')
		write(1, &"0123456789abcdef"[cur % 16], 1);
	else if (format == 'X')
		write(1, &"0123456789ABCDEF"[cur % 16], 1);
}

int print_pointer(unsigned long hex_addr)
{
	put_unsigned_long(hex_addr, 8);
	return (8);
}

int print_hex_int(char format, int val)
{
	put_hex_int(format, val);
	return (get_int_len(val, 16)); //확인 필요
}
