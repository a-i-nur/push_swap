#include "push_swap.h"

void    op_sa(t_state *state)
{
	if (!state || state->a.size < 2)
        return ;
	stack_swap_top(&state->a);
	op_print(state, "sa");
}

void    op_sb(t_state *state)
{
	if (!state || state->b.size < 2)
        return ;
	stack_swap_top(&state->b);
	op_print(state, "sb");
}

void    op_ss(t_state *state)
{
	int save_print;

    if (!state)
        return ;
	save_print = state->print;
	state->print = 0;
	op_sa(state);
	op_sb(state);
	state->print = save_print;
	if (state->a.size >= 2 || state->b.size >= 2)
		op_print(state, "ss");
}
