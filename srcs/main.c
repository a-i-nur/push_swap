#include "push_swap.h"

static t_state new_state()
{
	t_state state;

	state.a = stack_new('a');
	state.a = stack_new('b');
	state.print = 0;
	state.ops_count = 0;
	return (state);
}

int main(int argc, char *argv[])
{
	t_state state;
	// ft_printf("printf: %d %s\n", argc, argv[0]);
	state = new_state();
	parse_args(&state, argc, argv);
	if (is_sorted_stack(&state.a))
		return (0);
	if (assign_indexes(&state.a) == 0)
		error_exit(&state);
	if (&state.a.size <= 5) 
		sort_small(&state); 
	else
		sort_big(&state);
	free_state(&state);
	return (0);
}
