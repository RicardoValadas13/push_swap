/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:43:30 by ricardovala       #+#    #+#             */
/*   Updated: 2023/07/20 23:45:31 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_errors(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if(av[i][j] == '+' || av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dbl(t_lst **a)
{
	t_lst	*tmp;
	t_lst	*tmp1;

	tmp1 = *a;
	while (tmp1)
	{
		tmp = tmp1->next;
		while (tmp)
		{
			if (tmp->content == tmp1->content)
				return (1);
			tmp = tmp->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

// This function allows me to check the order of a given stack,
// if return = 1 then its ordered
int	check_order(t_lst **head)
{
	t_lst	*stack;

	stack = *head;
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}