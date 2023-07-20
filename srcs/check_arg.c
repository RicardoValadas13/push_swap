/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:43:30 by ricardovala       #+#    #+#             */
/*   Updated: 2023/07/20 11:51:06 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error(void)
{
	write(1, "error\n", 6);
}

void	ordered(void)
{
	write(1, "ordered\n", 8);
}

int	check_errors(t_lst **a)
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
	while (stack->next != NULL && stack != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}