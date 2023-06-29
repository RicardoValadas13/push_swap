#include "ft_printf.h"

void ft_flags(char ch, va_list args, long int *count)
{
    if (ch == 'c')
        ft_putchar(va_arg(args, int), count);
    else if (ch == 's')
        ft_putstr(va_arg(args, char *), count);
    else if (ch == 'p')
        ft_printhex(va_arg(args, unsigned long long int), 0, count);
    else if (ch == 'd' || ch == 'i')
        ft_putnbr(va_arg(args, int), count);
    else if (ch == 'u')
        ft_unsdec10(va_arg(args,unsigned int), count);
    else if (ch == 'x')
        ft_hexbase16lc(va_arg(args, unsigned int), count);
    else if (ch == 'X')
        ft_hexbase16uc(va_arg(args, unsigned int), count);
    else if (ch == '%')
        ft_putchar('%', count);
}
int ft_printf(const char *format, ...)
{
    va_list args;
    unsigned int i;
    long int count;

    i = 0;
    count = 0;
    va_start(args, format);
    if (!*format)
        return (0);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
            ft_flags(format[++i], args, &count);
        else
            ft_putchar(format[i], &count);
        i++;
    }
    va_end(args);
    return (count);
}

