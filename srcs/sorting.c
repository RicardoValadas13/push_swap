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

int ft_pos(t_lst *stack, t_lst *find)
{
    int i;

    i = 0;
    while(stack != NULL)
    {
        if (stack->content == find->content)
            return (i);
        stack = stack->next;
        i++;
    }
    return (i);
}

//The purpose of this function is to count the moves necessary
//to push a specific node to the other stack in its most efficent ways
int pushmove_calc(t_lst *stack, int size, int pos)
{
    int i;
    
    //In this case when the value is located in the lower half and
    //because of that i calculate the moves as if im doing the rotate move, and then
    //one push..
    if (pos < size / 2)
    {
        i = 0;
        while (stack != NULL)
        {
            stack = stack->prev;
            i++;
        }
    }
    //In this case when the value is located on the upper half of the stack it
    //is cheaper to do reverse rotate, so i calculate that number of moves, includind
    //the push..
    else if (pos >= size / 2)
    {
        i = 1;
        while (stack != NULL)
        {
            stack = stack->next;
            i++;
        }
    }
    else
        i = 0;
    return (i);
}

void    sort(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
    while (ft_lstsize(*stackA) > 3)
    {
        pa(stackA, stackB, counter);
        pa(stackA, stackB, counter);
        if ((*stackA)->content > ft_max(*stackB)->content)
            pa(stackA, stackB, counter);
        else


        pushmove_calc(ft_max((*stackA)), ft_lstsize(*stackA), ft_pos(*stackA, ft_max((*stackA))));
    }
    sort_three(stackA, counter);
    //first we push to values from the top of A to B

    
}
