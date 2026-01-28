#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_state	state;

	// ft_printf("printf: %d %s\n", argc, argv[0]);
	state = state_new();
	parse_args(&state, argc, argv);
	if (is_sorted_stack(&state.a))
	{
		state_free(&state);
		return (0);
	}
	if (assign_indexes(&state.a) == 0)
		error_exit(&state);
	sort_dispatch(&state);
	state_free(&state);
	return (0);
}
