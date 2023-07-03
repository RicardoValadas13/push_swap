#define PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
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

typedef struct 
{
    int				total_count;
} FunctionCounters;


int main(int ac, char **av);
int	ft_atoi(char const *nptr);
int	check_order(t_lst **stack);
t_lst	*create_head(int nbr);
void	add_to_stack(t_lst **lst, t_lst *new);
int	ft_lstsize(t_lst *lst);
void	*last_in_stack(t_lst *lst);
void	del_node(t_lst	**del);
void	sa(t_lst **stack, FunctionCounters *counter);
void	sb(t_lst **stack, FunctionCounters *counter);
void	ra(t_lst **stack, FunctionCounters *counter);
void	rb(t_lst **stack, FunctionCounters *counter);
void	rra(t_lst **stack, FunctionCounters *counter);
void	rrb(t_lst **stack, FunctionCounters *counter);
void	pa(t_lst **push, t_lst **rec, FunctionCounters *counter);
void	pb(t_lst **push, t_lst **rec, FunctionCounters *counter);
void    rr(t_lst **stackA, t_lst **stackB, FunctionCounters *counter);
void    rrr(t_lst **stackA, t_lst **stackB, FunctionCounters *counter);
void    ss(t_lst **stackA, t_lst **stackB, FunctionCounters *counter);
void	printresults(t_lst	*stackA, t_lst *stackB);
void    sort(t_lst **stackA, t_lst **stackB, FunctionCounters *counter);
void    sort_three(t_lst **stackA, FunctionCounters *counter);
int	descending(t_lst *stack);
t_lst *ft_min(t_lst *stack);
t_lst *ft_max(t_lst *stack);
int pushmove_calc(t_lst *stack, int size, int pos);
int ft_pos(t_lst *stack, t_lst *find);


