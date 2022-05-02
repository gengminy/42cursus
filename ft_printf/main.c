#include "ft_printf.h"
#include <stdio.h>

int main(){
    int n = 555;
	unsigned int u = 2500000000;
    char c = 'N';
    char str[] = "abcd1234efg";
	char *s;
	s = 0;
	

    ft_printf("raw text\n");
    ft_printf("percent : %%\n");
	ft_printf("percent test : %%p %%d %%%%s %%\n");
    ft_printf("%c %c %c\n", '0', '2', 0);
	printf("%c %c %c\n", '0', '2', 0);
    ft_printf("%s\n", s);
	printf("%s\n", s);

    ft_printf("%s\n", str);
    ft_printf("dec int : %d\n", n);
	ft_printf("hex int : %x orig: %d\n", n, n);
	ft_printf("hex int : %X orig: %d\n", -n, -n);
	ft_printf("unsigned int : %u\n", u);

	
	ft_printf("ft_printf pointer 0x1 : %p\n", 1);
	printf("printf pointer 0x1 : %p\n", (void *)1);
	ft_printf("ft_printf pointer 0x2 : %p\n", 2);
	printf("printf pointer 0x1 : %p\n",(void *) 2);
	ft_printf("ft_printf pointer 1000 : %p\n", 1000);
	printf("printf pointer 0x1 : %p\n",(void *) 1000);

	ft_printf("pointer of n : %p\n", &n);
	ft_printf("pointer of u : %p\n", &u);

	ft_printf("pointer of n : %p\n", &n);
	ft_printf("pointer of u : %p\n", &u);
	ft_printf("pointer of c : %p\n", &c);
	ft_printf("pointer of str : %p\n", str);

	ft_printf("address of ptr : %p\n", 0xEEFFAAEE);	

}