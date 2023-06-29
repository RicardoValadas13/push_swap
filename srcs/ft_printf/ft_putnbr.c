#include "ft_printf.h"

void    ft_putnbr(int n, long int *count)
{
    if (n == -2147483648)
    {
        ft_putstr("-2147483648", count);
        return ;
    }
    if (n < 0)
    {
        ft_putchar('-', count);
        n *= -1;
    }
    if (n >= 10)
        ft_putnbr(n / 10, count);
    ft_putchar(n % 10 + '0', count);
}