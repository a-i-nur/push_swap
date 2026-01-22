#include "push_swap.h"

void sort_small(t_state *state)
{
	int size;

	size = state->a.size;
	if (size <= 1)
		return ;
	if (size == 2)
		sort_small_2(state);
	else if (size == 3)
		sort_small_3(state);
	else if (size == 4)
		sort_small_4(state);
	else if (size == 5)
		sort_small_5(state);
}

