#include "push_swap.h"

void	sort_small_3(t_state *state)
{
	int	top_i;
	int	middle_i;
	int	bottom_i;

	top_i = state->a.top->index;
	middle_i = state->a.top->next->index;
	bottom_i = state->a.bottom->index;
	if (top_i < middle_i && middle_i < bottom_i)
		return ;
	if (top_i > bottom_i && bottom_i > middle_i)
		op_ra(state);
	else if (top_i > middle_i && middle_i > bottom_i)
	{
		op_sa(state);
		op_rra(state);
	}
	else if (middle_i > bottom_i && bottom_i > top_i)
	{
		op_sa(state);
		op_ra(state);
	}
	else if (bottom_i > top_i && top_i > middle_i)
		op_sa(state);
	else if (middle_i > top_i && top_i > bottom_i)
		op_rra(state);
}
