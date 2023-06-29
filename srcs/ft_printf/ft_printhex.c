#include "ft_printf.h"

void    ft_printhex(unsigned long long int n, int check, long int *count)
{
    if (!n)
		ft_putstr("(nil)", count);
	if (check == 0)
	{
		ft_putstr("0x", count);
	}
	if (n >= 16)
		ft_printhex(n / 16, ++check, count);
	ft_putchar("0123456789abcdef"[n % 16], count);
}