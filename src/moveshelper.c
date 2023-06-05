#include "./inc/push_swap.h"
void    dbl_rot_x(t_lst **stackA, t_lst *stackB)
{
    rot_x(&stackA);
    rot_x(&stackB);
}

void    dbl_rev_rot_x(t_lst **stackA, t_lst *stackB)
{
    rev_rot_x(&stackA);
    rev_rot_x(&stackB);
}

void    dbl_swap_x(t_lst **stackA, t_lst *stackB)
{
    swap_x(&stackA);
    swap_x(&stackB);
}
