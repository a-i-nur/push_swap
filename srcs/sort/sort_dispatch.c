#include "push_swap.h"

void	sort_dispatch(t_state *state)
{
	if (state->a.size <= SMALL_SORT_MAX)
		sort_small(state);
	else
		sort_big(state);
}
