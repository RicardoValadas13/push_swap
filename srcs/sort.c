/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:44 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/20 22:24:54 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This function sorts the stackA when it only contains 3 elemnets
// I hard coded this part because the number of cases are low
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

// The purpose of this function is to count the moves necessary
// to push a specific node to the other stack in its most efficent ways
// stack : it is the stack where i want to calculate the moves
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

void	sort_remaining(t_lst **a, t_lst **b, int mvs_a, int mvs_b)
{
	while (mvs_a != 0)
		mvs_a = remaining_rot_a(a, mvs_a);
	while (mvs_b != 0)
		mvs_b = remaining_rot_b(b, mvs_b);
}
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
		mvs = abs_val(topstack_calc(ft_lstsize(b), ft_pos(*b, mv_stackB(tmp,
						b)))) + abs_val(topstack_calc(ft_lstsize(a), ft_pos(*a,
					tmp))) + 1;
		if (mvs < optim_mvs || check++ == 0)
		{
			optim_mvs = mvs;
			optim_nbr = tmp;
		}
		tmp = tmp->next;
	}
	sort_stacks(a, b, topstack_calc(ft_lstsize(a), ft_pos(*a, optim_nbr)),
		topstack_calc(ft_lstsize(b), ft_pos(*b, mv_stackB(optim_nbr, b))));
}

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
void	check_sort(t_lst **a, t_lst **b)
{
	int	size;
	
	print_stacks(*a, *b);

	size = ft_lstsize(a);
	if (size > 3)
	{
			print_stacks(*a, *b);

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
	sort_stacks(a, b, topstack_calc(ft_lstsize(a), ft_pos(*a, ft_min(*a))), 0);
	print_stacks(*a, *b);
}
