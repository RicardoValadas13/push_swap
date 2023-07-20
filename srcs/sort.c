/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:44 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/21 00:36:39 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// The purpose of this function is to count the moves necessary
// to push a specific node to the other stack in its most efficent ways
// size : the size of the stack
// pos : the position of the number that i want to push
int	topstack_calc(int size, int pos)
{
	int	i;

	i = 0;
	if (pos == 1)
		return (0);
	if (pos < size / 2)
		i = pos - 1;
	else if (pos >= size / 2)
		i = -1 * (size - pos + 1);
	return (i);
}

// This is the function that represents my algorithm it calls all
// the necessary functions for him to work
void	sortingalg(t_lst **a, t_lst **b)
{
	int		mvs;
	int		check;
	int		optim_mvs;
	t_lst	*tmp;
	t_lst	*optim_nbr;

	mvs = 0;
	optim_mvs = 0;
	check = 0;
	optim_nbr = NULL;
	tmp = *a;
	while (tmp != NULL)
	{
		mvs = abs_val(topstack_calc(ft_lstsize(b), ft_pos(*b, mv_stack_b(tmp,
							b)))) + abs_val(topstack_calc(ft_lstsize(a), 
					ft_pos(*a, tmp))) + 1;
		if (mvs < optim_mvs || check++ == 0)
		{
			optim_mvs = mvs;
			optim_nbr = tmp;
		}
		tmp = tmp->next;
	}
	sort_stacks(a, b, topstack_calc(ft_lstsize(a), ft_pos(*a, optim_nbr)),
		topstack_calc(ft_lstsize(b), ft_pos(*b, mv_stack_b(optim_nbr, b))));
}

// This function is used to send back the values from stackb to stacka
// when stackb is already sorted in a descending way
void	sendback(t_lst **a, t_lst **b)
{
	if ((*b)->content > ft_max(*a)->content)
		sort_stacks(a, b, topstack_calc(ft_lstsize(a), ft_pos(*a, ft_min(*a))),
			0);
	else
		sort_stacks(a, b, topstack_calc(ft_lstsize(a), ft_pos(*a, ft_maxover(a,
						(*b)->content))), 0);
	pa(b, a);
}

// This function is the starting point of my algorithm, it checks the size of
// stacka and it decides which path to follow in order to order the stack.
void	check_sort(t_lst **a, t_lst **b)
{
	int	size;

	size = ft_lstsize(a);
	if (size > 3)
	{
		pb(a, b);
		pb(a, b);
		size = ft_lstsize(a);
		while (size > 3)
		{
			sortingalg(a, b);
			pb(a, b);
			size = ft_lstsize(a);
		}
	}
	sort_three(a);
	while (*b)
		sendback(a, b);
	if (ft_lstsize(a) > 3)
		sort_stacks(a, b, topstack_calc(ft_lstsize(a), ft_pos(*a, ft_min(*a))),
			0);
}
