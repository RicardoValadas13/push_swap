/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:44 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/06 14:28:56 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


//This function sorts the stackA when it only contains 3 elemnets
//I hard coded this parts because the number of cases are low
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

//This function returns the position of a passed (find) in a determined stack
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

int		head(t_lst	*stack)
{
	if (!stack)
		return (0);
	else if (stack->prev == NULL)
		return (1);
	else
		return (0);
}

//The purpose of this function is to count the moves necessary
//to push a specific node to the other stack in its most efficent ways
//stack : it is the stack where i want to calculate the moves
//size : the size of the stack
//pos : the position of the number that i want to push
int	topstack_calc(t_lst **stack, int size, int pos, int allow)
{
	int		i;
	t_lst	*temp;
	
	temp = stack;
	i = 0;
	if (head(stack))
		return (0);
	while (temp != NULL)
	{
		if (pos < size / 2)
		{
			temp = temp->prev;
			i++;
			if (allow)
				ra(*stack);
		}
		else
		{
			temp = temp->next;
			i++;
			if (allow)
				rra (*stack);
		}
	}
	return (i);
}

//This function returns the highest number 
//in the stack bellow the given number
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
//to push a certain number from stackA to stackB
int	optimal_tester(t_lst *stackA, t_lst *stackB)
{
	int moves;
	
	moves = 0;
	if (stackA->content > ft_max(stackB)->content
		|| stackA->content < ft_min(stackB)->content)
	{
		moves = topstack_calc(ft_max(stackB), ft_lstsize(stackB),
				ft_pos(stackB, ft_max(stackB)), 0);
	}
	else
	{
		moves = topstack_calc(ft_maxbelow(stackB, stackA->content),
				ft_lstsize(stackB), ft_pos(stackB, ft_maxbelow(stackB,
						stackA->content)), 0);
	}
	return (moves);
}


void	sort_everything(t_lst	*better, t_lst *stackA, t_lst *stackB)
{
	topstack_calc(better, ft_lstsize(stackA), ft_pos(stackA,temp), 1);
}
//Tenho de mudar isto de maneira a percorrer toda a lista
//Criar condicao que permita alterar o valor quando este e o menor 
void	sort(t_lst **stackA, t_lst **stackB)
{
	int		mvs;
	int		check;
	int		optim_mvs;
	t_lst	*temp;
	t_lst	*optim_mv;

	pa(stackA, stackB);
	pa(stackA, stackB);
	temp = *stackA;
	mvs = 0;
	optim_mvs = 0;
	check = 0;
	while (temp != NULL)
	{
		mvs = optimal_tester(temp, *stackB) + topstack_calc(temp, ft_lstsize(*stackA), ft_pos(*stackA,
					temp), 0) + 1;
		if (mvs < optim_mvs || check++ == 0)
		{
				optim_mvs = mvs;
				optim_mv = temp;
		}
		temp = temp->next;
	}
	sort_everything(temp, *stackA, *stackB);
	printf("\n\nBest to move : %d\nWith this moves : %d\n\n", optim_mv->content, optim_mvs);
}
