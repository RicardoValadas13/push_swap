#define PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_lst
{
  int nbr;
  void              *content;
  struct s_lst  *next;
}                    t_lista;

int main(int ac, char **av);