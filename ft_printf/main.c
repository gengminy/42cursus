#include "./ft_printf.c"

int main(){
    int n = 100;
    char c = 'N';
    char str[] = "abcd1234efg";

    ft_printf("raw text");
    ft_printf("%%");
    ft_printf("%c", c);
    ft_printf("%s", str);
    ft_printf("%d", n);
}