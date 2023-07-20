/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveshelper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2123/07/05 10:58:37 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/20 11:34:57 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rr(t_lst **stacka, t_lst **stackb)
{
	ra(stacka, 1);
	rb(stackb, 1);
	write(1, "rr\n", 3);
}

void	rrr(t_lst **stacka, t_lst **stackb)
{
	rra(stacka, 1);
	rrb(stackb, 1);
	write(1, "rrr\n", 4);
}

void	ss(t_lst **stacka, t_lst **stackb)
{
	sa(stacka, 1);
	sb(stackb, 1);
	write(1, "ss\n", 3);
}
