#include "push_swap.h"

void	sort_small_2(t_state *state)
{
	if (state->a.top->index > state->a.top->next->index)
		op_sa(state);
}
