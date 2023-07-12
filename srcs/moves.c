/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:30 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/12 12:23:24 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//This function performs the move sa or sb where the top 2 nodes of a stack change between them
void	sa(t_lst **a)
{
	t_lst	*top;

	if (ft_lstsize(a) < 2)
		return ;
	top = *a;
	(*a) = top->next;
	(*a)->prev = top;
	top->prev = NULL;
	if ((*a)->next != NULL)
	{
		top->next = (*a)->next;
		(*a)->next->prev = top;
	}
	else
		top->next = NULL;
	(*a)->next = top;
	write(1, "sa\n", 3);
}

void	sb(t_lst **b)
{
	t_lst	*top;

	if (ft_lstsize(b) < 2)
		return ;
	top = *b;
	*b = top->next;
	(*b)->prev = NULL;
	top->prev = *b;
	if ((*b)->next != NULL)
	{
		top->next = (*b)->next;
		(*b)->next->prev = top;
	}
	else
		top->next = NULL;
	(*b)->next = top;
	write(1, "sb\n", 3);
}

//This function performs the move raor rb where the first element of a stack
//goes to the last positions
void	ra(t_lst **a)
{
	t_lst	*top;
	t_lst	*last;

	if (ft_lstsize(a) < 2)
		return ;
	top = *a;
	last = last_in_stack(*a);
	*a = (*a)->next;
	(*a)->prev = NULL;
	last->next = top;
	top->prev = last;
	top->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_lst **b)
{
	t_lst	*top;
	t_lst	*last;

	if (ft_lstsize(b) < 2)
		return ;
	top = *b;
	last = last_in_stack(*b);
	*b = (*b)->next;
	(*b)->prev = NULL;
	last->next = top;
	top->prev = last;
	top->next = NULL;
	write(1, "rb\n", 3);
}

//This function performs the move rra or rrb where the last element becomes the first
void	rra(t_lst **a)
{
	t_lst	*prevLast;
	t_lst	*last;

	if (ft_lstsize(a) < 2)
		return ;
	last = last_in_stack(*a);
	prevLast = last->prev;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	prevLast->next = NULL;
	(*a) = last;
	write(1, "rra\n", 4);
}

void	rrb(t_lst **b)
{
	t_lst	*prevLast;
	t_lst	*last;

	if (ft_lstsize(b) < 2)
		return ;
	last = last_in_stack(*b);
	prevLast = last->prev;
	last->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	prevLast->next = NULL;
	(*b) = last;
	write(1, "rrb\n", 4);
}

//This function performs the pa or pb move where the first element of a stack is pushed
//to the other stack
void	pa(t_lst **b, t_lst **a)
{
	t_lst *node;

	if (!*b)
		return ;
	node = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = node;
	write(1, "pa\n", 3);
}

void	pb(t_lst **a, t_lst **b)
{
	t_lst *node;

	if (!*a)
		return ;
	node = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = node;
	write(1, "pb\n", 3);
}