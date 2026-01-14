#include "push_swap.h"

void	error_exit(t_state *state)
{
	write(2, "Error\n", 6);
	free_state(state);
	exit(1);
}
