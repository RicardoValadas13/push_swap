#include "../inc/push_swap.h"
 int	main(int ac, char **av)
{
	int i;
	t_lst *stackA;
	t_lst *stackB;
	t_lst *nodeA;
	int num;

	stackA = NULL;
	stackB = NULL;
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
		sort(&stackA);
		printresults(stackA, stackB);
		printf(GREEN "Now it is with this moves: \n" RESET);
		print_values();
	}
}

void print_values(int count, ...) {
    va_list args;
    va_start(args, count);
	int	value;
	int	i;

	i = 0;

    while (i < count)
	{
		value = va_arg(args, int);
		i++;
	}
	 
        printf("Value %d: %d\n", i + 1, value);

    va_end(args);
}

int main() {
    print_values(3, 10, 20, 30);
    print_values(4, 1, 2, 3, 4);
    return 0;
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
