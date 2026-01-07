#include "push_swap.h"

t_node  *pop_top(t_stack *stack)
{
    t_node *back_node;
    t_node *new_top;

    if (!stack || stack->size == 0)
        return NULL;
    back_node = stack->top;
    if (stack->size == 1)
    {
        stack->top = NULL;
        stack->bottom = NULL;
        stack->size = 0;
    }
    else if (stack->size > 1)
    {
        new_top = back_node->next;
        stack->top = new_top;
        new_top->prev = NULL;
        stack->size--;
    }
    back_node->next = NULL;
    back_node->prev = NULL;
    return (back_node);
}
