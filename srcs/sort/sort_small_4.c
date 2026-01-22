#include "push_swap.h"

void	sort_small_4(t_state *state)
{
	int	pos;

	pos = find_min_pos(&state->a);
	bring_pos_to_top(state, pos, 'a');
	op_pb(state);
	sort_small_3(state);
	op_pa(state);
}
