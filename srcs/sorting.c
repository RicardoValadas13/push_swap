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
    else if (ft_min(*stackA) == (*stackA))
    {
        rra(stackA, counter);
        sa(stackA, counter);
    }
    //checks if the first element is the max and its not in a descending order
    else if ((ft_max(*stackA) == (*stackA)) && !descending(*stackA))
        ra(stackA, counter);
    else
    {
        //if the middle value its the max then rra
        if (ft_max(*stackA) == (*stackA)->next)
            rra(stackA, counter);
        //if the middle value its the min then sa
        else if ((ft_min(*stackA) == (*stackA)->next))
            sa(stackA, counter);
    }
}

int moves_calc(t_lst *stack)
{
    int i;

    i = 0;
    while (stack != NULL)
    {
        ft_printf("STACK DATA : %d\n", stack->content);
        stack = stack->prev;
        i++;
    }
    //ft_printf("%d\n", stack->prev->content);
    //ft_printf("%d\n", stack->content);
    return (i);
}

void    sort(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
    if (ft_lstsize(*stackA) > 3)
    {
        (void)stackB;
        //pa(stackA, stackB, counter);
        ft_printf("moves : %d\n", moves_calc(ft_max((*stackA))));
    }
    else
    {
        sort_three(stackA, counter);
    }
    //first we push to values from the top of A to B

    
}
