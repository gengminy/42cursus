#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>

int	get_numlen_base_signed(long n, int base);
int	get_numlen_base_unsigned(unsigned long n, int base);

int print_ptr(unsigned long hex_addr);
int print_hex(char format, unsigned long val);

int print_int(int val);
int print_unsigned_int(unsigned int val);

int print_char(int val);
int print_str(char *val);

int ft_printf(const char *str, ...);

#endif