/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:42:16 by ricardovala       #+#    #+#             */
/*   Updated: 2023/07/21 00:31:38 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_lst **stacka, int wrt_dbl)
{
	swap(stacka);
	if (!wrt_dbl)
		write(1, "sa\n", 3);
}

void	sb(t_lst **stackb, int wrt_dbl)
{
	swap(stackb);
	if (!wrt_dbl)
		write(1, "sb\n", 3);
}
