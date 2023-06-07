#include "../inc/push_swap.h"
void    sort_small(t_lst **stackA)
{
    rev_rot_x(stackA);
}

void    sort(t_lst **stackA)
{
    if (ft_lstsize(*stackA) <= 3)
        sort_small(stackA);
}
