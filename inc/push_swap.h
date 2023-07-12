#define PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "../srcs/ft_printf/ft_printf.h"
#include "../srcs/libft/libft.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

typedef struct s_lst
{
	int				content;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef	struct m_lst
{
	char	*moves;
	struct	m_lst *next;
}			mvs_struct;


int main(int ac, char **av);
int	ft_atoi(char const *nptr);
int	check_order(t_lst **stack);
t_lst	*create_head(int nbr);
void	add_to_stack(t_lst **lst, t_lst *new);
int	ft_lstsize(t_lst **lst);
void	*last_in_stack(t_lst *lst);
void	del_node(t_lst	**del);
void	sa(t_lst **stack);
void	sb(t_lst **stack);
void	ra(t_lst **stack);
void	rb(t_lst **stack);
void	rra(t_lst **stack);
void	rrb(t_lst **stack);
void	pa(t_lst **b, t_lst **a);
void	pb(t_lst **a, t_lst **b);
void    rr(t_lst **a, t_lst **b);
void    rrr(t_lst **a, t_lst **b);
void    ss(t_lst **a, t_lst **b);
void    check_sort(t_lst **a, t_lst **b);
void    sort_three(t_lst **a);
int	descending(t_lst *stack);
t_lst *ft_min(t_lst *stack);
t_lst *ft_max(t_lst *stack);
int topstack_calc(t_lst *stack, int size, int pos);
int ft_pos(t_lst *stack, t_lst *find);
int    optimal_tester(t_lst *b, t_lst *stack_mv);
int		head(t_lst	*stack);
void	sortingalg(t_lst *a, t_lst *b);
t_lst	*mv_stackB(t_lst *a, t_lst *b);
//void	sort_everything(t_lst	*better, t_lst *stackA, t_lst *stackB);



