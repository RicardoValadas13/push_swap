/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:38:01 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/06 14:25:14 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	int					i;
	t_lst				*stack_a;
	t_lst				*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac < 2)
		return (ft_printf("%s", "Try again"));
	else if (ac > 1)
	{
		while (av[i])
			add_to_stack(&stack_a, create_head(ft_atoi(av[i++])));
	}
	if (check_order(&stack_a))
		printresults(stack_a, stack_b);
	else
	{
		sort(&stack_a, &stack_b);
		printresults(stack_a, stack_b);
	}
}

void	printresults(t_lst *stack_a, t_lst *stack_b)
{
	ft_printf("Tamanho da lista: %d\n", ft_lstsize(stack_a));
	ft_printf("%s", "---STACK A------STACK B----\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a && stack_b)
		{
			printf("     %d     |      %d     \n", stack_a->content,
					stack_b->content);
		}
		else if (!stack_a && stack_b)
		{
			printf("            |      %d     \n", stack_b->content);
		}
		else if (stack_a && !stack_b)
		{
			printf("     %d     |             \n", stack_a->content);
		}
		stack_a = stack_a ? stack_a->next : NULL;
		stack_b = stack_b ? stack_b->next : NULL;
	}
}
