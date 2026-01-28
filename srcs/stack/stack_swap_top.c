#include "push_swap.h"

void	stack_swap_top(t_stack *stack)
{
	t_node	*old_top;
	t_node	*new_top;
	t_node	*third;

	if (!stack || stack->size < 2)
		return ;
	old_top = stack->top;
	new_top = old_top->next;
	old_top->next = new_top->next;
	old_top->prev = new_top;
	new_top->next = old_top;
	new_top->prev = NULL;
	stack->top = new_top;
	third = old_top->next;
	if (stack->size == 2)
	{
		old_top->next = NULL;
		stack->bottom = old_top;
	}
	else if (stack->size > 2)
	{
		third->prev = old_top;
	}
}
