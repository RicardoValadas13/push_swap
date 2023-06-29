#include "../inc/push_swap.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void    rr(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
    ra(stackA, counter);
    rb(stackB, counter);
    counter->total_count--;
}

void    rrr(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
    rra(stackA, counter);
    rrb(stackB, counter);
    counter->total_count--;
}

void    ss(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
    sa(stackA, counter);
    sb(stackB, counter);
    counter->total_count--;
}
