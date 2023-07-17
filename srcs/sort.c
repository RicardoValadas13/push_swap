/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:44 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/17 10:17:38 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//This function sorts the stackA when it only contains 3 elemnets
//I hard coded this part because the number of cases are low
void	sort_three(t_lst **a)
{
	if (check_order(a))
		return ;
	if (descending(*a))
	{
		sa(a);
		rra(a);
	}
	else if (ft_min(*a) == (*a))
	{
		rra(a);
		sa(a);
	}
	else if ((ft_max(*a) == (*a)) && !descending(*a))
		ra(a);
	else
	{
		if (ft_max(*a) == (*a)->next)
			rra(a);
		else if ((ft_min(*a) == (*a)->next))
			sa(a);
	}
}

//This function returns the position of a passed (find) in a determined (stack)
int	ft_pos(t_lst *stack, t_lst *find)
{
	int	i;
	printf("stack : %d\nfind : %d\n",stack->content,find->content);
	i = 0;
	while (stack != NULL)
	{
		if (stack->content == find->content)
		{
	printf("i : %d\n",i);
			
			return (i);
		}
		stack = stack->next;
		i++;
	}
	printf("i : %d\n",i);
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
int	optimal_tester(t_lst *b, t_lst *mv_a)
{
	int moves;
	
	moves = topstack_calc(mv_a, ft_lstsize(&b),
				ft_pos(b, mv_a));
	return (moves);
}

//This fucntion returns the elemente i need to move
//in stackB
t_lst	*mv_stackB(t_lst *a, t_lst *b)
{
	t_lst *stack_mv;
	
	if (a->content > ft_max(b)->content
		|| a->content < ft_min(b)->content)
		stack_mv = ft_max(b);		
	else
		stack_mv = ft_maxbelow(b, a->content);
	return (stack_mv);
}

void	sort_everything(t_lst	*a, t_lst *b, t_lst *mv_a, t_lst *mv_b)
{
	printf("\n------------------------\n\nmv_b : %d\nb : %d %d %d\n\n",mv_b->content, b->content,b->next->content,b->next->next->content);

	while (mv_b->content != b->content)
	{
		if (ft_lstsize(&b) / 2 > ft_pos(b, mv_b))
		{
			printf("head : %d\n",b->content);
			rb(&b);
		}
		else if (ft_lstsize(&b) / 2 < ft_pos(b, mv_b))
		{
			printf("head : %d\n",b->content);
			rrb(&b);
		}
	}

	while (mv_a->content != a->content)
	{
		if (ft_lstsize(&a) / 2 > ft_pos(a, mv_a))
		{
			printf("head : %d\n",b->content);
			ra(&a);
		}
		else if (ft_lstsize(&a) / 2 < ft_pos(a, mv_a))
		{
			printf("head : %d\n",b->content);	
			rra(&a);
		}
	}
	pb(&a, &b);
	return ;
}

//This is the function that represents my algorithm it calls all
//the necessary functions for him to work
void	sortingalg(t_lst *a, t_lst *b)
{
	int		mvs;
	int		check;
	int		optim_mvs;
	t_lst	*temp;
	t_lst	*optim_nbr;
	
	temp = a;
	mvs = 0;
	optim_mvs = 0;
	check = 0;
	optim_nbr = NULL;
	while (temp->next != NULL)
	{
		mvs = optimal_tester(b, mv_stackB(a, b)) + topstack_calc(temp, ft_lstsize(&a), ft_pos(a,
					temp));	
		if (mvs < optim_mvs || check++ == 0)
		{
				optim_mvs = mvs;
				optim_nbr = temp;
		}
		temp = temp->next;
	}
	printf("sortingalg\n");
	sort_everything(a, b, optim_nbr, mv_stackB(optim_nbr,b));
}

void	check_sort(t_lst **a, t_lst **b)
{
	int size;
	
	size = ft_lstsize(a);
	if (size > 3)
	{
		pb(a, b);
		pb(a, b);
		pb(a, b);
		size = ft_lstsize(a);
		printf("Size: %d\n", size);
		last_in_stack(*a);
		while (size > 3)
		{
			sortingalg(*a,*b);
			size = ft_lstsize(a);
			printf("Size: %d\n", size);
		}
	}
	sort_three(a);
}
