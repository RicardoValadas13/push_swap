/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:41:51 by ricardovala       #+#    #+#             */
/*   Updated: 2023/07/21 00:31:12 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_lst **stackb, t_lst **stacka)
{
	push(stackb, stacka);
	write(1, "pa\n", 3);
}

void	pb(t_lst **stacka, t_lst **stackb)
{
	push(stacka, stackb);
	write(1, "pb\n", 3);
}
