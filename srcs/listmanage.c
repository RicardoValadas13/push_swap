#include "../inc/push_swap.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

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

void	*last_lst(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	del_node(t_lst	**del)
{
	if (*del)
	{
		(*del)->prev = NULL;
		(*del)->next = NULL;
		free(*del);
		*del = NULL;
	}
}