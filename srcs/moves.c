/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:30 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/13 13:04:45 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//This function performs the move sa or sb where the top 2 nodes of a stack change between them
void	sa(t_lst **a)
{
	t_lst	*head;

	if (!a || ft_lstsize(a) < 2)
		return ;
	head = *a;
	(*a) = head->next;
	(*a)->prev = head;
	head->prev = NULL;
	if ((*a)->next != NULL)
	{
		head->next = (*a)->next;
		(*a)->next->prev = head;
	}
	else
		head->next = NULL;
	(*a)->next = head;
	write(1, "sa\n", 3);
}

void	sb(t_lst **b)
{
	t_lst	*head;

	if (ft_lstsize(b) < 2)
		return ;
	head = *b;
	*b = head->next;
	(*b)->prev = NULL;
	head->prev = *b;
	if ((*b)->next != NULL)
	{
		head->next = (*b)->next;
		(*b)->next->prev = head;
	}
	else
		head->next = NULL;
	(*b)->next = head;
	write(1, "sb\n", 3);
}

//This function performs the move ra or rb where the first element of a stack
//goes to the last positions

void ra(t_lst **a)
{
    t_lst *head;
	t_lst *temp;
    t_lst *last;

    if (!a || ft_lstsize(a) < 2)
        return;
    temp = *a;
	head = (*a)->next;
    last = last_in_stack(*a);
	head->prev = NULL;
	temp->prev = last;
	temp->next = NULL;
	last->next = head;
    *a = head;
    write(1, "ra\n", 3);
}

void	rb(t_lst **b)
{
t_lst *head;
	t_lst *temp;
    t_lst *last;

    if (!b || ft_lstsize(b) < 2)
        return;
    temp = *b;
	head = (*b)->next;
    last = last_in_stack(*b);
	head->prev = NULL;
	temp->prev = last;
	temp->next = NULL;
	last->next = head;
	*b = head;
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