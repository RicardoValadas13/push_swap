/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveshelper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:37 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/05 10:58:38 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"

void	rr(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
	ra(stackA, counter);
	rb(stackB, counter);
	counter->total_count--;
}

void	rrr(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
	rra(stackA, counter);
	rrb(stackB, counter);
	counter->total_count--;
}

void	ss(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
	sa(stackA, counter);
	sb(stackB, counter);
	counter->total_count--;
}
