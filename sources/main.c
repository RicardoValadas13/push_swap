#include "push_swap.h"

t_lista  *Add_To_Stack(int nb)
{
  t_lista *node;

  node = (t_list *)malloc(sizeof(t_list));
  if (!node)
    return (NULL);
  node->nb;
  node->next

}

int main(int ac, char **av)
{
  t_list stack_rec;
  int i;

  i = 0;
  //Error Message
  if (ac != 2)
  {
    if (ac < 2)
      printf("%s", "Not enough arguments!! TRY AGAIN");
    if (ac > 2)
      printf("%s", "Too many arguments!! TRY AGAIN");
  }
  //Store the values received in a linked list
  while (av[1][i] != NULL)
  {
    Add_To_Stack(av[1][i++]);
  }  
}

