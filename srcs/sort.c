/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:44 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/05 12:16:34 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"

//This function sorts the stackA when it only contains 3 elemnets
//I hard coded this parts because the number of cases are low
void	sort_three(t_lst **stackA, FunctionCounters *counter)
{
	if (check_order(stackA))
		return ;
	if (descending(*stackA))
	{
		sa(stackA, counter);
		rra(stackA, counter);
	}
	else if (ft_min(*stackA) == (*stackA))
	{
		rra(stackA, counter);
		sa(stackA, counter);
	}
	else if ((ft_max(*stackA) == (*stackA)) && !descending(*stackA))
		ra(stackA, counter);
	else
	{
		if (ft_max(*stackA) == (*stackA)->next)
			rra(stackA, counter);
		else if ((ft_min(*stackA) == (*stackA)->next))
			sa(stackA, counter);
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
	while (temp != NULL)
	{
		if (pos < size / 2)
		{
			temp = temp->prev;
			i++;
		}
		else
		{
			temp = temp->next;
			i++;
		}
	}
	//printf("Topstack_calc\n Stack : %d\n Size: %d\n Pos: %d\n\n",
			//stack->content, size, pos);
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

//This function retunrns the number of moves 
//to push a certain number from stackA to stackB
int	optimal_tester(t_lst *stackA, t_lst *stackB, int moves)
{
	if (stackA->content > ft_max(stackB)->content
		|| stackA->content < ft_min(stackB)->content)
	{
		moves += topstack_calc(ft_max(stackB), ft_lstsize(stackB),
				ft_pos(stackB, ft_max(stackB)));
	}
	else
	{
		moves += topstack_calc(ft_maxbelow(stackB, stackA->content),
				ft_lstsize(stackB), ft_pos(stackB, ft_maxbelow(stackB,
						stackA->content)));
	}
	return (moves);
}

//Tenho de mudar isto de maneira a percorrer toda a lista
//Criar condicao que permita alterar o valor quando este e o menor 
void	sort(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
	int		mvs;
	int		mvsbef;
	t_lst	*temp;

	pa(stackA, stackB, counter);
	pa(stackA, stackB, counter);
	pa(stackA, stackB, counter);
	pa(stackA, stackB, counter);
	pa(stackA, stackB, counter);
	temp = *stackA;
	mvsbef = 0;
	while (temp != NULL)
	{
		mvs = 0;
		mvs = optimal_tester(temp, *stackB, mvs);
		if (mvsbef < mvs + topstack_calc(temp, ft_lstsize(*stackA),
				ft_pos(*stackA, temp)) && mvsbef != 0)
			break ;
		mvsbef = mvs + topstack_calc(temp, ft_lstsize(*stackA), ft_pos(*stackA,
					temp));
		temp = temp->next;
	}
	printf("Necessary moves : %d\n\n", mvsbef);
}
