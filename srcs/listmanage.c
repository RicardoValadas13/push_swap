/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:32:33 by rbenjami          #+#    #+#             */
/*   Updated: 2023/07/13 11:57:24 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


//This function creates the head of a stack
t_lst	*create_head(int nbr)
{
	t_lst	*node;

	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->content = nbr;
	node->next = NULL;
	if (node->content != nbr)
	{
		free(node);
		return (NULL);
	}
	return (node);
}

//This function adds nodes to a stack
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

//This function returns the size of a stack
int	ft_lstsize(t_lst **lst)
{
	int		cnt;
	t_lst	*temp;

	temp = *lst;
	cnt = 1;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return (cnt);
}

//This function returns the last node of the stack
t_lst	*last_in_stack(t_lst *lst)
{
	t_lst	*temp;

	temp = lst;
	if (temp == NULL)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

//This function deletes a node of a given stack
void	del_node(t_lst **del)
{
	t_lst	*prev_node;
	t_lst	*next_node;

	if (*del == NULL)
		return ;
	prev_node = (*del)->prev;
	next_node = (*del)->next;
	if (prev_node != NULL)
		prev_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = prev_node;
	free(*del);
	*del = NULL;
}
