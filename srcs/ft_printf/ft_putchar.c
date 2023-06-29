#include "ft_printf.h"

void    ft_putchar(char c, long int *count)
{
    write(1, &c, 1);
    *count += 1;
}