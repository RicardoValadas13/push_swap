#define PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_lst
{
	int				content;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;


int main(int ac, char **av);
int	ft_atoi(char const *nptr);
t_lst	*first_in_stack(int nbr);
void	add_to_stack(t_lst **lst, t_lst *new);
int	ft_lstsize(t_lst *lst);
void	*last_lst(t_lst *lst);
void	del_node(t_lst	**del);
void	swap_x(t_lst **stack);
void	rot_x(t_lst **stack);
void	rev_rot_x(t_lst **stack);
void	push_x(t_lst **push, t_lst **rec);
void    dbl_rot_x(t_lst **stackA, t_lst *stackB);
void    dbl_rev_rot_x(t_lst **stackA, t_lst *stackB);
void    dbl_swap_x(t_lst **stackA, t_lst *stackB);
