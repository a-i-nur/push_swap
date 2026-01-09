#include "push_swap.h"

void	op_rra(t_state *state)
{
	if (!state || state->a.size < 2)
		return ;
	stack_reverse_rotate(&state->a);
	op_print(state, "rra");
}

void	op_rrb(t_state *state)
{
	if (!state || state->b.size < 2)
		return ;
	stack_reverse_rotate(&state->b);
	op_print(state, "rrb");
}

void	op_rrr(t_state *state)
{
	int save_print;

	if (!state)
		return ;
	save_print = state->print;
	state->print = 0;
	op_rra(state);
	op_rrb(state);
	state->print = save_print;
	if (state->a.size >= 2 || state->b.size >= 2)
		op_print(state, "rrr");
}
