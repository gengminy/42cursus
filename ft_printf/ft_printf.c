#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}





void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

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




int	get_int_len(int n, int base)
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





int print_char(char val)
{
	write(1, &val, 1);
	return (1);
}

int print_str(char *val)
{
	ft_putstr_fd(val, 1);
	return (ft_strlen(val));
}

int print_int(int val)
{
	ft_putnbr_fd(val, 1);
	return (get_int_len(val, 10));
}






void	put_unsigned_int(unsigned int val)
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





void	put_unsigned_long(unsigned long hex_addr, int len)
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


int print_pointer(unsigned long hex_addr)
{
	put_unsigned_long(hex_addr, 8);
	return (8); //FFFFFFFF
}




void	put_hex_int(char format, int val)
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
int print_hex_int(char format, int val)
{
	put_hex_int(format, val);
	return (get_int_len(val, 16)); //확인 필요
}






int print_var(const char format, va_list ap)
{
	if (format == 'c')
		return (print_char(va_arg(ap, int)));
	else if (format == 's')
		return (print_str(va_arg(ap, char *)));
	else if (format == 'p')
		return (print_pointer(va_arg(ap, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (print_int(va_arg(ap, int)));
	else if (format == 'u')
		return (print_unsigned_int(va_arg(ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (print_hex_int(format, va_arg(ap, int)));
	else if (format == '%')
		return (write(1, "%", 1));
	return (0);
}


int ft_printf(const char *str, ...)
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
			ret += print_var(*str, ap);
		}
		else
			ret += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (ret);
}





int main(){
    int n = 555;
	unsigned int u = 2500000000;
    char c = 'N';
    char str[] = "abcd1234efg";
	

    ft_printf("raw text\n");
    ft_printf("percent : %%\n");
	ft_printf("percent test : %%p %%d %%%%s %%\n");
    ft_printf("%c\n", c);
    ft_printf("%s\n", str);
    ft_printf("dec int : %d\n", n);
	ft_printf("hex int : %x orig: %d\n", n, n);
	ft_printf("hex int : %X orig: %d\n", -n, -n);
	ft_printf("unsigned int : %u\n", u);

	ft_printf("pointer of n : %p\n", &n);
	ft_printf("pointer of u : %p\n", &u);
	ft_printf("pointer of c : %p\n", &c);
	ft_printf("pointer of str : %p\n", str);

	ft_printf("address of ptr : %p\n", 0xEEFFAAEE);	

}