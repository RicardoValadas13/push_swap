#include "../inc/push_swap.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

//This function sorts the stackA when it only contains 3 elemnets
//I hard coded this parts because the number of cases are low 
void    sort_three(t_lst **stackA, FunctionCounters *counter)
{
    //checks if its in descending order, if it is then proceeds to do two moves
    if (check_order(stackA))
        return ;
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

//This function returns the position of a passed (find) in a determined stack
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
//stack : it is the stack where i want to calculate the moves
//size : the size of the stack
//pos : the position of the number that i want to push
int pushmove_calc(t_lst *stack, int size, int pos)
{
    int i;
    t_lst *temp;

    temp = stack;
    i = 0;
    while (temp != NULL)
    {
        if (pos < size / 2)
        {
            temp = temp->prev;
            i++;
        }
        else
        {
            temp = temp->next;
            i++;
        }
    }
    return (i);
}

void    sort(t_lst **stackA, t_lst **stackB, FunctionCounters *counter)
{
    /* while (ft_lstsize(*stackA) > 3)
    { */
        pa(stackA, stackB, counter);
        pa(stackA, stackB, counter);
      
        /* if ((*stackA)->content > ft_max(*stackB)->content)
            pa(stackA, stackB, counter);
        else */
        printf("moves : %d \n", pushmove_calc(ft_max((*stackB)), ft_lstsize(*stackB), ft_pos(*stackB, ft_max((*stackB)))));
   /*  } */
    sort_three(stackA, counter);
    //first we push to values from the top of A to B
    
    
}
