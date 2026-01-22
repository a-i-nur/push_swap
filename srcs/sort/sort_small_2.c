#include "push_swap.h"

void sort_small_2(t_state *state)
{
	if (state->a.top->value > state->a.top->next->value)
        op_sa(state);
}
