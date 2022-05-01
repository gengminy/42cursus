#include "ft_printf.h"

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