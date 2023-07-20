#define PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../srcs/ft_printf/ft_printf.h"
#include "../srcs/libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_lst
{
	int				content;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct m_lst
{
	char			*moves;
	struct m_lst	*next;
}					mvs_struct;

int					main(int ac, char **av);
int					ft_atoi(char const *nptr);
int					check_order(t_lst **stack);
t_lst				*create_head(int nbr);
void				add_to_stack(t_lst **lst, t_lst *new);
int					ft_lstsize(t_lst **lst);
t_lst				*last_in_stack(t_lst *lst);
void				del_node(t_lst **del);
void				swap(t_lst **stack);
void				sa(t_lst **stacka, int wrt_dbl);
void				sb(t_lst **stackb, int wrt_dbl);
void				rotate(t_lst **stack);
void				ra(t_lst **stacka, int wrt_dbl);
void				rb(t_lst **stackb, int wrt_dbl);
void				rev_rotate(t_lst **stack);
void				rra(t_lst **stacka, int wrt_dbl);
void				rrb(t_lst **stackb, int wrt_dbl);
void				push(t_lst **push, t_lst **receive);
void				pa(t_lst **push, t_lst **receive);
void				pb(t_lst **push, t_lst **receive);
void				rr(t_lst **stacka, t_lst **stackb);
void				rrr(t_lst **stacka, t_lst **stackb);
void				ss(t_lst **stacka, t_lst **stackb);
void				check_sort(t_lst **a, t_lst **b);
void				sort_three(t_lst **a);
int					descending(t_lst **stack);
t_lst				*ft_min(t_lst *stack);
t_lst				*ft_max(t_lst *stack);
int					topstack_calc(int size, int pos);
int					ft_pos(t_lst *stack, t_lst *find);
void				sortingalg(t_lst **a, t_lst **b);
t_lst				*mv_stackB(t_lst *a, t_lst **b);
void				sendback(t_lst **a, t_lst **b);
t_lst				*ft_maxover(t_lst **stack, int nbr);
t_lst				*ft_maxbelow(t_lst **stack, int nbr);
int					check_dbl(t_lst **a);
int					check_errors(char *str);
void				sort_stacks(t_lst **a, t_lst **b, int mvs_a, int mvs_b);
void				sort_remaining(t_lst **a, t_lst **b, int mvs_a, int mvs_b);
int					abs_val(int val);
void				print_stacks(t_lst *stackA, t_lst *stackB);
int					remaining_rot_b(t_lst **b, int mvs_b);
int					remaining_rot_a(t_lst **a, int mvs_a);

