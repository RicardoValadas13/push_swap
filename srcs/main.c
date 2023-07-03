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
	//I call this function in order to set my counter in my struct to 0
	ft_memset(&counter, 0, sizeof(FunctionCounters));
	i = 1;
	if (ac < 2)
		return (ft_printf("%s", "Try again"));
	else if (ac > 1)
	{
		while (av[i])
		{
			num = ft_atoi(av[i]);
			nodeA = create_head(num);
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
		printf("stackB : %d\n", stackB->content);
		printresults(stackA, stackB);
	}
}
void	printresults(t_lst	*stackA, t_lst *stackB)
{
	ft_printf("Tamanho da lista: %d\n", ft_lstsize(stackA));
	printf("stackB : %d\n", stackB->content);
	ft_printf("%s", "---STACK A------STACK B----\n");
	while (stackA != NULL || stackB != NULL)
	{
		if (stackA && stackB)
		{
			printf("stackA & stackB \n");
			printf("     %d     |      %d     \n", stackA->content, stackB->content);
		}
		else if (!stackA && stackB)
		{
			printf("!stackA & stackB \n");
			printf("            |      %d     \n", stackB->content);
		}
		else if (stackA && !stackB)
		{
			printf("stackA & !stackB \n");
			printf("     %d     |             \n", stackA->content);
		}
		
		stackA = stackA ? stackA->next : NULL;
		stackB = stackB ? stackB->next : NULL;
	}
}


