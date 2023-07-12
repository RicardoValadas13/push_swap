/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:27:54 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/12 13:22:56 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


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
	t_lst	*stack;

	stack = *head;
	while (stack->next != NULL && stack != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

//This function checks if the order of a stack is descending
int	descending(t_lst *stack)
{
	int		i;
	t_lst	*temp;

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

