#include "./inc/push_swap.h"
void	swap_x(t_lst **stack)
{
	t_lst	*top;

	if (ft_lstsize(*stack) < 2)
		return ;
	top = *stack;
	*stack = (*stack)->next;
	del_node(&(*stack)->prev);
	top->prev = *stack;
	if ((*stack)->next != NULL)
	{
		top->next = (*stack)->next;
		(*stack)->next->prev = top;
	}
	(*stack)->prev = NULL;
	(*stack)->next = top;
}

void	rot_x(t_lst **stack)
{
	t_lst	*top;
	t_lst	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	top = *stack;
	last = last_lst(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = top;
	top->prev = last;
	top->next = NULL;
}

void	rev_rot_x(t_lst **stack)
{
	t_lst	*prevLast;
	t_lst	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	last = last_lst(*stack);
	prevLast = last->prev;
	last->prev = NULL;
	last->next = *stack; 
	(*stack)->prev = last;
	prevLast->next = NULL;
	(*stack) = last;
}

void	push_x(t_lst **push, t_lst **rec)
{
	t_lst	*node;

	if (!*push)
		return ;
	node = *push;
	*push = node->next;
	if (*push != NULL)
		(*push)->prev = NULL;
	node->prev = NULL;
	node->next = *rec;
	if (*rec != NULL)
		(*rec)->prev = node;
	*rec = node;
}