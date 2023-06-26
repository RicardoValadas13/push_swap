#include "../inc/push_swap.h"
#include <string.h>

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
	memset(&counter, 0, sizeof(FunctionCounters));
	i = 1;
	if (ac < 2)
		return (printf("%s", "Try again"));
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
		printf(GREEN "This stack is ordered \n" RESET);
		printresults(stackA, stackB);
	}
	else
	{
		printf(RED "This stack is not ordered \n" RESET);
		printf(GREEN "Now it is with this moves: \n" RESET);
		sort(&stackA, &stackB, &counter);
		printf("It was solved with %d moves\n", counter.total_count);
		printresults(stackA, stackB);
	}
}
void	printresults(t_lst	*stackA, t_lst *stackB)
{
	t_lst	*A;
	t_lst	*B;

	A = stackA;
	B = stackB;
	printf(CYAN "Tamanho da lista: %d\n" RESET, ft_lstsize(stackA));
	printf(BLUE "%s", "---STACK A------STACK B----\n" RESET);
	while (A != NULL || B != NULL)
	{
		if (A && B)
			printf("     %d     |      %d     \n", A->content, B->content);
		else if (!A && B)
			printf("            |      %d     \n", B->content);
		else if (A && !B)
			printf("     %d     |             \n", A->content);
		
		A = A ? A->next : NULL;
		B = B ? B->next : NULL;
	}
}
