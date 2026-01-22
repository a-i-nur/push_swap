#include "push_swap.h"

void sort_small_5(t_state *state)
{
	int pos;
	int i;

	i = 0;
	while (i < 2)
	{
		pos = find_min_pos(&state->a);
		bring_pos_to_top_a(state, pos);
		op_pb(state);
		i++;
	}
	sort_small_3(state);
	if (state->b.top->index < state->b.top->next->index)
		op_sb(state);
	op_pa(state);
	op_pa(state);
}
