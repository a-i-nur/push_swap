#include "push_swap.h"

t_stack	stack_new(char name)
{
	t_stack	new_stack;

	new_stack.name = name;
	new_stack.size = 0;
	new_stack.top = NULL;
	new_stack.bottom = NULL;
	return (new_stack);
}
