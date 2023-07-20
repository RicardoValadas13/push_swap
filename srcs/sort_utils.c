/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:30:44 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/20 15:20:27 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This fucntion returns the min value in a given stack
t_lst	*ft_min(t_lst *stack)
{
	t_lst	*temp;
	t_lst	*min_node;
	int		min_value;

	if (stack == NULL)
		return (NULL);
	temp = stack;
	min_node = temp;
	min_value = temp->content;
	while (temp)
	{
		if (temp->content < min_value)
		{
			min_value = temp->content;
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

// This fucntion returns the max value in a given stack
t_lst	*ft_max(t_lst *stack)
{
	t_lst	*temp;
	t_lst	*max_node;

	if (stack == NULL)
		return (NULL);
	temp = stack;
	max_node = temp;
	while (temp)
	{
		if (temp->content > max_node->content)
			max_node = temp;
		temp = temp->next;
	}
	return (max_node);
}
// This function returns the highest number
// in the stack bellow the passed number (nbr)
t_lst	*ft_maxbelow(t_lst **stack, int nbr)
{
	t_lst	*maxnbr;
	t_lst	*tmp;

	maxnbr = NULL;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->content < nbr && (maxnbr == NULL
				|| tmp->content > maxnbr->content))
			maxnbr = tmp;
		tmp = tmp->next;
	}
	return (maxnbr);
}

t_lst	*ft_maxover(t_lst **stack, int nbr)
{
	t_lst	*maxnbr;
	t_lst	*tmp;

	maxnbr = NULL;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->content > nbr && (maxnbr == NULL
				|| tmp->content < maxnbr->content))
			maxnbr = tmp;
		tmp = tmp->next;
	}
	return (maxnbr);
}

// This function returns the position of a passed (find) in a determined (stack)
int	ft_pos(t_lst *stack, t_lst *find)
{
	int	i;

	i = 1;
	while (stack != NULL)
	{
		if (stack->content == find->content)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}
