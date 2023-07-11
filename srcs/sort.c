/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:44 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/11 12:55:49 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


//This function sorts the stackA when it only contains 3 elemnets
//I hard coded this part because the number of cases are low
void	sort_three(t_lst **stackA)
{
	if (check_order(stackA))
		return ;
	if (descending(*stackA))
	{
		sa(stackA);
		rra(stackA);
	}
	else if (ft_min(*stackA) == (*stackA))
	{
		rra(stackA);
		sa(stackA);
	}
	else if ((ft_max(*stackA) == (*stackA)) && !descending(*stackA))
		ra(stackA);
	else
	{
		if (ft_max(*stackA) == (*stackA)->next)
			rra(stackA);
		else if ((ft_min(*stackA) == (*stackA)->next))
			sa(stackA);
	}
}

//This function returns the position of a passed (find) in a determined (stack)
int	ft_pos(t_lst *stack, t_lst *find)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->content == find->content)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

//This function returns 1 if the element passed is the top of the stack and 0
//if not
int		head(t_lst	*stack)
{
	if (stack->prev == NULL)
		return (1);
	else
		return (0);
}

//The purpose of this function is to count the moves necessary
//to push a specific node to the other stack in its most efficent ways
//stack : it is the stack where i want to calculate the moves
//size : the size of the stack
//pos : the position of the number that i want to push
int	topstack_calc(t_lst *stack, int size, int pos)
{
	int		i;
	t_lst	*temp;
	
	temp = stack;
	i = 0;
	if (head(stack))
		return (0);
	if (pos < size / 2)
	{
		while (temp->prev != NULL)
		{
			temp = temp->prev;
			i++;
		}
	}
	else
	{
		while (temp != NULL)
		{
			temp = temp->next;
			i++;
		}
	}
	
	return (i);
}

//This function returns the highest number 
//in the stack bellow the passed number (nbr)
t_lst	*ft_maxbelow(t_lst *stack, int nbr)
{
	t_lst	*maxnbr;

	maxnbr = stack;
	while (stack != NULL)
	{
		if (stack->content < nbr)
			maxnbr = stack;
		stack = stack->next;
	}
	return (maxnbr);
}

//This function returns the number of moves 
//to put the number of stackB correspondent 
//to the number of the number of StackA that 
//has to be above, in the top of the stackB.
//Two Conditions:
//First one : When the number in stackA is gonna
//the new max or min value in stackB when pushed
//Second one : When is not the max or min, so I
//have to use ft_maxbellow in order to find the 
//number that has to be bellow the number I gonna push
int	optimal_tester(t_lst *stackB, t_lst *stack_mv)
{
	int moves;
	
	moves = topstack_calc(stack_mv, ft_lstsize(stackB),
				ft_pos(stackB, stack_mv));
	return (moves);
}

//This fucntion returns the elemente i need to move
//in stackB
t_lst	*mv_stackB(t_lst *stackA, t_lst *stackB)
{
	t_lst *stack_mv;
	
	stack_mv = NULL;
	if (stackA->content > ft_max(stackB)->content
		|| stackA->content < ft_min(stackB)->content)
		stack_mv = ft_max(stackB);		
	else
		stack_mv = ft_maxbelow(stackB, stackA->content);
	return (stack_mv);
}

void	sort_everything(t_lst	*stackA, t_lst *stackB, t_lst *mv_stacka, t_lst *mv_stackb)
{
	while (!head(mv_stackb))
	{
		if (ft_lstsize(stackB) / 2 > ft_pos(stackB, mv_stackb))
		{
			rb(&stackB);
			stackB = stackB->prev;
		}
		else if (ft_lstsize(stackB) / 2 < ft_pos(stackA, mv_stackb))
		{
			rrb(&stackB);
			stackB = stackB->next;	
		}
	}
	while (!head(mv_stacka))
	{
		if (ft_lstsize(stackA) / 2 > ft_pos(stackA, mv_stacka))
		{
			ra(&stackA);
			stackA = stackA->prev;
		}	
		else if (ft_lstsize(stackA) / 2 < ft_pos(stackA, mv_stacka))
		{
			rra(&stackA);
			stackA = stackA->next;
		}
	}
	pa(&stackA, &stackB);
	return ;
}


//This is the function that represents my algorithm it calls all
//the necessary function for him to work
void	sortingalg(t_lst *stackA, t_lst *stackB)
{
	int		mvs;
	int		check;
	int		optim_mvs;
	t_lst	*temp;
	t_lst	*optim_nbr;
	
	temp = stackA;
	mvs = 0;
	optim_mvs = 0;
	check = 0;
	while (temp->next != NULL)
	{
		mvs = optimal_tester(stackB, mv_stackB(stackA, stackB)) + topstack_calc(temp, ft_lstsize(stackA), ft_pos(stackA,
					temp));	
		if (mvs < optim_mvs || check++ == 0)
		{
				optim_mvs = mvs;
				optim_nbr = temp;
		}
		temp = temp->next;
	}
	sort_everything(stackA, stackB, optim_nbr, mv_stackB(optim_nbr,stackB));
	//printf("\n\nMove (stackA): %d\nMove (stackB): %d\n\n", optim_nbr->content, mv_stackB(optim_nbr,stackB)->content);
}

void	check_sort(t_lst **stackA, t_lst **stackB)
{

	if (ft_lstsize(*stackA) > 3)
	{
		pa(stackA, stackB);
		pa(stackA, stackB);
		while (ft_lstsize(*stackA) > 3)
		{
			/* printf("here\n");
			printf("size: %d\n",ft_lstsize(*stackA)); */
			sortingalg(*stackA,*stackB);
		}
	}
	sort_three(stackA);
}
