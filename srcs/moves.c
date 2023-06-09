#include "../inc/push_swap.h"
void	sa(t_lst **stack, FunctionCounters *counter)
{
	t_lst	*top;

	if (ft_lstsize(*stack) < 2)
		return ;
	top = *stack;
	*stack = top->next;
	(*stack)->prev = NULL;
	top->prev = *stack;
	if ((*stack)->next != NULL)
	{
		top->next = (*stack)->next;
		(*stack)->next->prev = top;
	}
	else
		top->next = NULL;
	(*stack)->next = top;
	counter->total_count++;
	write(1, "sa\n", 3);
}

void	sb(t_lst **stack, FunctionCounters *counter)
{
	t_lst	*top;

	if (ft_lstsize(*stack) < 2)
		return ;
	top = *stack;
	*stack = top->next;
	(*stack)->prev = NULL;
	top->prev = *stack;
	if ((*stack)->next != NULL)
	{
		top->next = (*stack)->next;
		(*stack)->next->prev = top;
	}
	else
		top->next = NULL;
	(*stack)->next = top;
	counter->total_count++;
	write(1, "sb\n", 3);
}

void	ra(t_lst **stack, FunctionCounters *counter)
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
	counter->total_count++;
	write(1, "ra\n", 3);
}

void	rb(t_lst **stack, FunctionCounters *counter)
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
	counter->total_count++;
	write(1, "rb\n", 3);
}

void	rra(t_lst **stack, FunctionCounters *counter)
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
	counter->total_count++;
	write(1, "rra\n", 4);
}

void	rrb(t_lst **stack, FunctionCounters *counter)
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
	counter->total_count++;
	write(1, "rrb\n", 4);
}

void	pa(t_lst **push, t_lst **rec, FunctionCounters *counter)
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
	counter->total_count++;
	write(1, "pa\n", 3);
}

void	pb(t_lst **push, t_lst **rec, FunctionCounters *counter)
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
	counter->total_count++;
	write(1, "pb\n", 3);
}