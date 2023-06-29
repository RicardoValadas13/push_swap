#include "ft_printf.h"

void    ft_hexbase16uc(unsigned int n, long int *count)
{
    char *hex;

    hex = "0123456789ABCDEF";
    if (n >=16)
        ft_hexbase16uc(n / 16, count);
    ft_putchar(hex[n % 16], count);
}