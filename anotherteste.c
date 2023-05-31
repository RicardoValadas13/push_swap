#include <stdio.h>
#include <stdlib.h>

typedef struct s_lst
{
    int content;
    struct s_lst *prev;
    struct s_lst *next;
} t_lst;

t_lst *create_node(int num)
{
    t_lst *new_node = (t_lst *)malloc(sizeof(t_lst));
    if (new_node == NULL)
        return ;

    new_node->content = num;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void add_to_stack(t_lst **stack, t_lst *new_node)
{
    if (*stack == NULL)
    {
        *stack = new_node;
    }
    else
    {
        t_lst *current = *stack;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

int get_stack_size(t_lst *stack)
{
    int size = 0;
    t_lst *current = stack;
    while (current != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}

void swap_top_two_nodes(t_lst **stack)
{
    if (*stack != NULL && (*stack)->next != NULL)
    {
        t_lst *node1 = *stack;
        t_lst *node2 = (*stack)->next;

        int temp = node1->content;
        node1->content = node2->content;
        node2->content = temp;
    }
}

void move_top_node(t_lst **source, t_lst **destination)
{
    if (*source == NULL)
    {
        printf("Source stack is empty.\n");
        return;
    }

    t_lst *top_node = *source;
    *source = (*source)->next;
    if (*source != NULL)
    {
        (*source)->prev = NULL;
    }

    top_node->prev = NULL;
    top_node->next = *destination;
    if (*destination != NULL)
    {
        (*destination)->prev = top_node;
    }

    *destination = top_node;
}

void print_stack(t_lst *stack)
{
    t_lst *current = stack;
    while (current != NULL)
    {
        printf("%d\n", current->content);
        current = current->next;
    }
}

void free_stack(t_lst *stack)
{
    while (stack != NULL)
    {
        t_lst *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int main(int argc, char **argv)
{
    t_lst *stack = NULL;

    if (argc < 2)
    {
        printf("No arguments provided.\n");
        return 0;
    }

    int i = 1;
    while (argv[i])
    {
        int num = atoi(argv[i]);
        t_lst *new_node = create_node(num);
        add_to_stack(&stack, new_node);
        i++;
    }

    printf("Stack size: %d\n", get_stack_size(stack));

    swap_top_two_nodes(&stack);

    printf("Stack content:\n");
    print_stack(stack);

    free_stack(stack);
    return 0;
}
