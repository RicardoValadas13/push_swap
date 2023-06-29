#include "../inc/push_swap.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void    sort_three(t_lst **stackA, FunctionCounters *counter)
{
    //checks if its in descending order, if it is then proceeds to do two moves
    if (descending(*stackA))
    {
        sa(stackA, counter);
        rra(stackA, counter);
    }
    //checks if the first element is the min
    else if (ft_min(*stackA) == (*stackA)->content)
    {
        rra(stackA, counter);
        sa(stackA, counter);
    }
    //checks if the first element is the max and its not in a descending order
    else if ((ft_max(*stackA) == (*stackA)->content) && !descending(*stackA))
        ra(stackA, counter);
    else
    {
        //if the middle value its the max then rra
        if (ft_max(*stackA) == (*stackA)->next->content)
            rra(stackA, counter);
        //if the middle value its the min then sa
        else if ((ft_min(*stackA) == (*stackA)->next->content))
            sa(stackA, counter);
    }
}

void    sort(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
    while (ft_lstsize(*stackA) > 3)
    {
        pa(stackA, stackB, counter);
        pa(stackA, stackB, counter);
    }
        sort_three(stackA, counter);
    //first we push to values from the top of A to B

    
}
