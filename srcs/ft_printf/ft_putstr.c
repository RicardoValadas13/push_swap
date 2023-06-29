#include "ft_printf.h"

void	ft_putstr(char *s, long int *count)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}