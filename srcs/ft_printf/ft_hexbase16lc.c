#include "ft_printf.h"

void    ft_hexbase16lc(unsigned int n, long int *count)
{
    char *hex;

    hex = "0123456789abcdef";
    if (n >=16)
        ft_hexbase16lc(n / 16, count);
    ft_putchar(hex[n % 16], count);
}
