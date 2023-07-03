#include "../inc/push_swap.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

//This function is a reproduction of the atoi function, with this i transform 
//a char  representing a number into to a int
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

//This function allows me to check the order of a given stack, 
//if return = 1 then its ordered
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

//This function checks if the order of a stack is descending
int	descending(t_lst *stack)
{
	int i;
	t_lst *temp;
	
	i = stack->content;
	temp = stack;
	while (temp)
	{
		if (i < temp->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

//This function is used to count the number of moves that were made to organize the stacks
void	ft_count()
{
	static int counter = 0;
	counter++;
}

//This fucntion returns the min value in a given stack
t_lst *ft_min(t_lst *stack)
{
    if (stack == NULL)
        return NULL;

	t_lst *temp;
    t_lst *minNode; 
    int minValue;

	temp = stack;
	minNode = temp;
	minValue = temp->content;
	while (temp)
    {
        if (temp->content < minValue)
        {
            minValue = temp->content;
            minNode = temp;
        }
        temp = temp->next;
    }

    return (minNode);
}

//This fucntion returns the max value in a given stack
t_lst *ft_max(t_lst *stack)
{
    if (stack == NULL)
        return NULL;

	t_lst *temp;
    t_lst *maxNode; 
    int maxValue; 

	temp = stack;
	maxNode = temp;
	maxValue = temp->content;
	while (temp)
    {
        if (temp->content > maxValue)
        {
            maxValue = temp->content;
            maxNode = temp;
        }
        temp = temp->next;
    }
    return (maxNode);
}


