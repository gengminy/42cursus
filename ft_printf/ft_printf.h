#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>

int print_pointer(unsigned long hex_addr);
int print_hex_int(char format, int val);

int print_int(int val);
int print_unsigned_int(unsigned int val);

int print_char(char val);
int print_str(char *val);

int ft_printf(const char *str, ...);

#endif