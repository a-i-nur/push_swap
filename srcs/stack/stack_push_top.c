#include "push_swap.h"

void	stack_push_top(t_stack *stack, t_node *node)
{
	t_node	*old_top;

	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
		node->prev = NULL;
		node->next = NULL;
		stack->size = 1;
	}
	else if (stack->size > 0)
	{
		old_top = stack->top;
		node->prev = NULL;
		node->next = old_top;
		old_top->prev = node;
		stack->top = node;
		stack->size++;
	}
}
