/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:30 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/17 12:52:28 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//This function performs the move sa or sb where the top 2 nodes of a stack change between them
void	swap(t_lst **stack)
{
	t_lst	*node;

	if (!stack || ft_lstsize(stack) < 2)
		return ;
	node = *stack;
	(*stack) = node->next;
	(*stack)->prev = NULL;
	node->prev = (*stack);
	if ((*stack)->next != NULL)
	{
		node->next = (*stack)->next;
		(*stack)->next->prev = node;
	}
	else
		node->next = NULL;
	(*stack)->next = node;
}

void	sa(t_lst	**stacka)
{
	swap(stacka);
	write(1, "sa\n", 3);
}

void	sb(t_lst	**stackb)
{
	swap(stackb);
	write(1, "sb\n", 3);
}
//This function performs the move ra or rb where the first element of a stack
//goes to the last positions

void rotate(t_lst **stack)
{
	t_lst *head;
	t_lst *temp;
	t_lst *last;

	if (!stack || ft_lstsize(stack) < 2)
		return;
	temp = *stack;
	head = (*stack)->next;
	head->prev = NULL;
	last = last_in_stack(*stack);
	temp->prev = last;
	temp->next = NULL;
	last->next = temp;
	*stack = head;
}

void	ra(t_lst **stacka)
{
	rotate(stacka);
  write(1, "ra\n", 3);
}

void	rb(t_lst **stackb)
{
	rotate(stackb);
    write(1, "rb\n", 3);
}
//This function performs the move rra or rrb where the last element becomes the first
void	rev_rotate(t_lst **stack)
{
	t_lst	*last;

	if (ft_lstsize(stack) < 2)
		return ;
	last = last_in_stack(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = (*stack);
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_lst **stacka)
{
	rev_rotate(stacka);
	write(1, "rra\n", 4);
}

void	rrb(t_lst **stackb)
{
	rev_rotate(stackb);
	write(1, "rrb\n", 4);
}


//This function performs the pa or pb move where the first element of a stack is pushed
//to the other stack
void	push(t_lst **push, t_lst **receive)
{
	t_lst *node;

	if (!*push)
		return ;
	node = *push;
	*push = (*push)->next;
	if (*push)
		(*push)->prev = NULL;
	node->next = *receive;
	if (*receive)
		(*receive)->prev = node;
	*receive = node;
}

void	pa(t_lst	**stacka, t_lst	**stackb)
{
	push(stackb, stacka);
	write(1, "pa\n", 3);
}

void	pb(t_lst	**stacka, t_lst	**stackb)
{
	push(stacka, stackb);
	write(1, "pb\n", 3);
}