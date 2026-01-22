#include "push_swap.h"

t_state state_new()
{
	t_state state;

	state.a = stack_new('a');
	state.b = stack_new('b');
	state.print = 1;
	state.ops_count = 0;
	return (state);
}