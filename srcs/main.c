#include "../inc/push_swap.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

int	main(int ac, char **av)
{
	int i;
	t_lst *stackA;
	t_lst *stackB;
	t_lst *nodeA;
	FunctionCounters counter;
	int num;

	stackA = NULL;
	stackB = NULL;

	//remember to change this to the function i have on my library
	ft_memset(&counter, 0, sizeof(FunctionCounters));
	i = 1;
	if (ac < 2)
		return (ft_printf("%s", "Try again"));
	else if (ac > 1)
	{
		while (av[i])
		{
			num = ft_atoi(av[i]);
			nodeA = first_in_stack(num);
			add_to_stack(&stackA, nodeA);
			i++;
		}
	}
	if (check_order(&stackA))
	{
		ft_printf("This stack is ordered \n\n");
		printresults(stackA, stackB);
	}
	else
	{
		ft_printf("This stack is not ordered \n\n");
		ft_printf("Now it is with this moves: \n");
		sort(&stackA, &stackB, &counter);
		ft_printf("It was solved with %d moves\n", counter.total_count);
		printresults(stackA, stackB);
	}
}
void	printresults(t_lst	*stackA, t_lst *stackB)
{
	t_lst	*A;
	t_lst	*B;

	A = stackA;
	B = stackB;
	ft_printf("Tamanho da lista: %d\n", ft_lstsize(stackA));
	ft_printf("%s", "---STACK A------STACK B----\n");
	while (A != NULL || B != NULL)
	{
		if (A && B)
			ft_printf("     %d     |      %d     \n", A->content, B->content);
		else if (!A && B)
			ft_printf("            |      %d     \n", B->content);
		else if (A && !B)
			ft_printf("     %d     |             \n", A->content);
		
		A = A ? A->next : NULL;
		B = B ? B->next : NULL;
	}
}
