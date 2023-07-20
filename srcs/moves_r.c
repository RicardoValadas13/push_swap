/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:40:13 by ricardovala       #+#    #+#             */
/*   Updated: 2023/07/21 00:31:25 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_lst **stacka, int wrt_dbl)
{
	rev_rotate(stacka);
	if (!wrt_dbl)
		write(1, "rra\n", 4);
}

void	rrb(t_lst **stackb, int wrt_dbl)
{
	rev_rotate(stackb);
	if (!wrt_dbl)
		write(1, "rrb\n", 4);
}

void	ra(t_lst **stacka, int wrt_dbl)
{
	rotate(stacka);
	if (!wrt_dbl)
		write(1, "ra\n", 3);
}

void	rb(t_lst **stackb, int wrt_dbl)
{
	rotate(stackb);
	if (!wrt_dbl)
		write(1, "rb\n", 3);
}
