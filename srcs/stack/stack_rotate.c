#include "push_swap.h"

void    stack_rotate(t_stack *stack)
{
	t_node *old_top;
	t_node *old_bottom;
	t_node *new_top;

	if (!stack || stack->size < 2)
		return ;
	if (stack->size >= 2)
	{
		old_top = stack->top;
		new_top = old_top->next;
		old_bottom = stack->bottom;
		new_top->prev = NULL;
		stack->top = new_top;
		old_bottom->next = old_top;
		old_top->prev = old_bottom;
		old_top->next = NULL;
		stack->bottom = old_top;
	}
}
