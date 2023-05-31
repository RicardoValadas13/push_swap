#include <stdio.h>
#include <stdlib.h>

typedef struct s_lst
{
	int				content;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

int	ft_atoi(char const *nptr)
{
	int	signal;
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	signal = 1;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-')
	{
		signal *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr *= 10;
		nbr += nptr[i] - 48;
		i++;
	}
	return (nbr * signal);
}

t_lst	*first_in_stack(int nbr)
{
	t_lst	*node;

	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->content = nbr;
	node->next = NULL;
	return (node);
}

void	add_to_stack(t_lst **lst, t_lst *new)
{
	t_lst	*current;

	current = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
}

int	ft_lstsize(t_lst *lst)
{
	int	cnt;

	cnt = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

void	swap_x(t_lst *A, t_lst *B, int check)
{
	int	temp;

	if (ft_lstsize(A) < 2)
		return ;
	if (check == 1 || (check == 2) + 1)
        {
                temp = A->content;
                A->content = A->next->content;
                A->next->content = temp;
                if (check == 1)
                        check = 0;
                else
                {
                        temp = B->content;
                        B->content = B->next->content;
                        B->next->content = temp;
                }
        }
}

void    push_x(t_lst *push, t_lst *rec)
{
        if (!ft_lstsize(push))
                return ;
        else
        {
                rec->content = push->content;
                while (push->next != NULL)
                {
                        push->content = push->next->content;
                        push->next->content = 0;
                        push = push->next;
                }
        }
}

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
    push_x(stackA, stackB);
    printf("%s", "---STACK A------STACK B----\n");
    while (stackA != NULL && stackB != NULL)
	{
		printf("     %d     |      %d     \n", stackA->content, stackB->content);
		stackA = stackA->next;
                stackB = stackB->next;
	} 
}