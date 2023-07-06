/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:30:44 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/06 13:31:02 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//This fucntion returns the min value in a given stack
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

//This fucntion returns the max value in a given stack
t_lst	*ft_max(t_lst *stack)
{
	t_lst	*temp;
	t_lst	*max_node;
	int		max_value;

	if (stack == NULL)
		return (NULL);
	temp = stack;
	max_node = temp;
	max_value = temp->content;
	while (temp)
	{
		if (temp->content > max_value)
		{
			max_value = temp->content;
			max_node = temp;
		}
		temp = temp->next;
	}
	return (max_node);
}
