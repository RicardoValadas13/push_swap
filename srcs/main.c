/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:38:01 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/18 14:27:33 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	int					i;
	t_lst				*a;
	t_lst				*b;

	a = NULL;
	b = NULL;
	i = 1;
	if (ac < 2)
		return (ft_printf("%s", "Try again"));
	else if (ac > 1)
	{
		while (av[i])
			add_to_stack(&a, create_head(ft_atoi(av[i++])));
	}
	if (check_order(&a))
		error() ;
    else if (check_errors(&a))
        error();
	else
		check_sort(&a, &b);
}

void    error()
{
    write(1, "error\n", 6);
}

int check_errors(t_lst **a)
{
    t_lst   *tmp;
    t_lst   *tmp1;

    tmp1 = *a;
    while (tmp1)
    {
        tmp = tmp1->next;
        while (tmp)
        {
            if (tmp->content == tmp1->content)
                return (1);
            tmp = tmp->next;
        }
        tmp1 = tmp1->next;
    }
    return (0);
}

void print_stacks(t_lst *stackA, t_lst *stackB)
{
    t_lst *tempA = stackA;
    t_lst *tempB = stackB;

    while (tempA != NULL || tempB != NULL) {
        if (tempA != NULL) {
            printf("%-8d", tempA->content);
            tempA = tempA->next;
        } else {
            printf("         ");
        }

        printf("  |  ");

        if (tempB != NULL) {
            printf("%-8d", tempB->content);
            tempB = tempB->next;
        }

        printf("\n");
    }

    printf("--------  |  --------\n");
    printf("Stack A   |  Stack B\n\n\n");
}

