#include <stdio.h>
#include <stdlib.h>

typedef struct s_lst
{
	int content;
	struct s_lst *prev;
	struct s_lst *next;
} t_lst;

int     ft_atoi(char const *nptr)
{
        int     signal;
        int     nbr;
        int     i;

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

t_lst *first_in_stack(int nbr)
{
	t_lst *node;

	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->content = nbr;
	node->next = NULL;
	return (node);
}

void add_to_stack(t_lst **lst, t_lst *new)
{
	t_lst *current;

	current = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current -> next = new;
        new -> prev = current;
	}
}

int main(int ac, char **av)
{
	int i;
	t_lst *lista;
    t_lst *node;
    int num;
    
    lista = NULL;
	i = 1;
	if (ac < 2)
		return (printf("%s", "Try again"));
	else if (ac > 1)
	{
        while (av[i])
        {
            num = ft_atoi(av[i]);
            node = first_in_stack(num);
            add_to_stack(&lista, node);
            i++;
		}
	}
    while (lista != NULL)
    {
        printf("%d\n", lista->content);
        lista = lista->next;
    }
}