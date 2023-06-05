#include "./inc/push_swap.h"
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
	printf("Tamanho da lista: %d\n", ft_lstsize(stackA));
	//push_x(&stackA, &stackB);
	//swap_x(&stackA);
	//push_x(&stackA,&stackB);
	rev_rot_x(&stackA);
	printf("%s", "---STACK A------STACK B----\n");
	while (stackA != NULL || stackB != NULL)
	{
		if (stackA && stackB)
			printf("     %d     |      %d     \n", stackA->content, stackB->content);
		else if (!stackA && stackB)
			printf("            |      %d     \n", stackB->content);
		else if (stackA && !stackB)
			printf("     %d     |             \n", stackA->content);
		
		stackA = stackA ? stackA->next : NULL;
		stackB = stackB ? stackB->next : NULL;
	}

}

