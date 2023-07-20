/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:27:54 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/20 11:50:45 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This function is a reproduction of the atoi function, with this i transform
// a char  representing a number into to a int
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

// This function checks if the order of a stack is descending
int	descending(t_lst **stack)
{
	int		i;
	t_lst	*temp;

	temp = *stack;
	i = temp->content;
	while (temp)
	{
		if (i < temp->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	abs_val(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

// This fucntion returns the elements i need to move
// in stackB
t_lst	*mv_stackB(t_lst *a, t_lst **b)
{
	t_lst	*stack_mv;

	if (a->content > ft_max(*b)->content || a->content < ft_min(*b)->content)
		stack_mv = ft_max(*b);
	else
		stack_mv = ft_maxbelow(b, a->content);
	return (stack_mv);
}