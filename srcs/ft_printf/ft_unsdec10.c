#include "ft_printf.h"

void    ft_unsdec10(unsigned int n, long int *count)
{
    if (n >= 10)
        ft_unsdec10(n / 10, count);
    ft_putchar(n % 10 + '0', count);
}