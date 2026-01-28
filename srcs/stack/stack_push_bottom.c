#include "push_swap.h"

void	stack_push_bottom(t_stack *stack, t_node *node)
{
	t_node	*old_bottom;

	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->bottom = node;
		stack->top = node;
		node->prev = NULL;
		node->next = NULL;
		stack->size = 1;
	}
	else if (stack->size > 0)
	{
		old_bottom = stack->bottom;
		node->prev = old_bottom;
		node->next = NULL;
		old_bottom->next = node;
		stack->bottom = node;
		stack->size++;
	}
}
