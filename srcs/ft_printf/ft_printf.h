#ifndef FPRINTF_H
# define FPRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int     ft_printf(const char *format, ...);
void    ft_hexbase16lc(unsigned int n, long int *count);
void    ft_hexbase16uc(unsigned int n, long int *count);
void    ft_printhex(unsigned long long int n, int check, long int *count);
void    ft_putchar(char c, long int *count);
void    ft_putnbr(int n, long int *count);
void	ft_putstr(char *s, long int *count);
void    ft_unsdec10(unsigned int n, long int *count);

#endif