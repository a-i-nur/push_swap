#include "push_swap.h"

void	op_ra(t_state *state)
{
	if (!state || state->a.size < 2)
		return ;
	stack_rotate(&state->a);
	op_print(state, "ra");
}

void	op_rb(t_state *state)
{
	if (!state || state->b.size < 2)
		return ;
	stack_rotate(&state->b);
	op_print(state, "rb");
}

void	op_rr(t_state *state)
{
	int	save_print;

	if (!state)
		return ;
	save_print = state->print;
	state->print = 0;
	op_ra(state);
	op_rb(state);
	state->print = save_print;
	if (state->a.size >= 2 || state->b.size >= 2)
		op_print(state, "rr");
}
