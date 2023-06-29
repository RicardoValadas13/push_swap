#include "../inc/push_swap.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

int	ft_atoi(char const *nptr)
{
	int	signal;
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	signal = 1;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-')
	{
		signal *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr *= 10;
		nbr += nptr[i] - 48;
		i++;
	}
	return (nbr * signal);
}

int	check_order(t_lst **head)
{	
	t_lst *stack;

	stack = *head;
	while (stack->next !=NULL && stack != NULL)
	{
		if (stack->content > stack->next->content)
			return(0); 
		stack = stack->next;
	}
	return(1);
}

int	descending(t_lst *stack)
{
	int i;

	i = stack->content;
	while (stack)
	{
		if (i < stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_count()
{
	static int counter = 0;
	counter++;
}

int ft_min(t_lst *stack)
{
    int i;

    i = stack->content;
    while (stack)
    {
        if (stack->content < i)
            i = stack->content;
        stack = stack->next;
    }
    return (i);
}

int ft_max(t_lst *stack)
{
    int i;

    i = stack->content;
    while (stack)
    {
        if (stack->content > i)
            i = stack->content;
        stack = stack->next;
    }
    return (i);
}