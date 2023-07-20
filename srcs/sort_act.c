/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:01:16 by ricardovala       #+#    #+#             */
/*   Updated: 2023/07/21 00:34:57 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This function sorts the stackA when it only contains 3 elemnets
void	sort_three(t_lst **a)
{
	if (check_order(a))
		return ;
	if (descending(a))
	{
		sa(a, 0);
		rra(a, 0);
	}
	else if (ft_min(*a)->content == (*a)->content)
	{
		rra(a, 0);
		sa(a, 0);
	}
	else if ((ft_max(*a)->content == (*a)->content) && !descending(a))
		ra(a, 0);
	else if (ft_max(*a)->content == (*a)->next->content)
		rra(a, 0);
	else if (ft_min(*a)->content == (*a)->next->content)
		sa(a, 0);
}

int	remaining_rot_a(t_lst **a, int mvs_a)
{
	if (mvs_a < 0)
	{
		rra(a, 0);
		mvs_a++;
	}
	else if (mvs_a > 0)
	{
		ra(a, 0);
		mvs_a--;
	}
	return (mvs_a);
}

int	remaining_rot_b(t_lst **b, int mvs_b)
{
	if (mvs_b < 0)
	{
		rrb(b, 0);
		mvs_b++;
	}
	else if (mvs_b > 0)
	{
		rb(b, 0);
		mvs_b--;
	}
	return (mvs_b);
}

// This function takes the mvs from a and b and performs the rotations
// in each stack
void	sort_remaining(t_lst **a, t_lst **b, int mvs_a, int mvs_b)
{
	while (mvs_a != 0)
		mvs_a = remaining_rot_a(a, mvs_a);
	while (mvs_b != 0)
		mvs_b = remaining_rot_b(b, mvs_b);
}

// This function checks if its possible to do a double rotation and
// if it is, it adjusts the mvs from a and b, in order to perform the
// remaining single rotations.
void	sort_stacks(t_lst **a, t_lst **b, int mvs_a, int mvs_b)
{
	if (mvs_a < 0 && mvs_b < 0)
	{
		while (mvs_a != 0 && mvs_b != 0)
		{
			rrr(a, b);
			mvs_a++;
			mvs_b++;
		}
	}
	else if (mvs_a > 0 && mvs_b > 0)
	{
		while (mvs_a != 0 && mvs_b != 0)
		{
			rr(a, b);
			mvs_a--;
			mvs_b--;
		}
	}
	sort_remaining(a, b, mvs_a, mvs_b);
}
