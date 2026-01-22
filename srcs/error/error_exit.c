#include "push_swap.h"

void	error_exit(t_state *state)
{
	write(2, "Error\n", 6);
	state_free(state);
	exit(1);
}
