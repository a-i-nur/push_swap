#include "push_swap.h"

void    stack_reverse_rotate(t_stack *stack)
{
	t_node *old_top;
	t_node *old_bottom;
	t_node *new_bottom;

	if (!stack || stack->size < 2)
		return ;
	if (stack->size >= 2)
	{
		old_bottom = stack->bottom;
		new_bottom = old_bottom->prev;
		old_top = stack->top;
		new_bottom->next = NULL;
		stack->bottom = new_bottom;
		old_bottom->prev = NULL;
		old_bottom->next = old_top;
		old_top->prev = old_bottom;
		stack->top = old_bottom;
	}
}
