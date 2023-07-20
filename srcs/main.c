/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:38:01 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/20 23:46:47 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_lst	*a;
	t_lst	*b;

	a = NULL;
	b = NULL;
	i = 1;
	if (ac > 1 && !check_errors(av))
	{
		while (av[i])
			add_to_stack(&a, create_head(ft_atoi(av[i++])));
		if (!check_dbl(&a))
		{
			check_sort(&a, &b);
			return (write(1,"\nDONE\n",6));
		}
	}
	return (write(1,"error\n",6));
}


void	print_stacks(t_lst *stackA, t_lst *stackB)
{
	t_lst	*tempA;
	t_lst	*tempB;

	tempA = stackA;
	tempB = stackB;
	while (tempA != NULL || tempB != NULL)
	{
		if (tempA != NULL)
		{
			printf("%-8d", tempA->content);
			tempA = tempA->next;
		}
		else
		{
			printf("         ");
		}
		printf("  |  ");
		if (tempB != NULL)
		{
			printf("%-8d", tempB->content);
			tempB = tempB->next;
		}
		printf("\n");
	}
	printf("--------  |  --------\n");
	printf("Stack A   |  Stack B\n\n\n");
}
