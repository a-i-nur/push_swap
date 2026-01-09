#include "push_swap.h"

void	op_pa(t_state *state)
{
	t_node *top_node_b;

	if (!state || state->b.size == 0)
		return ;
	top_node_b = stack_pop_top(&state->b);
	stack_push_top(&state->a, top_node_b);
	op_print(state, "pa");
}

void	op_pb(t_state *state)
{
	t_node *top_node_a;

	if (!state || state->a.size == 0)
		return ;
	top_node_a = stack_pop_top(&state->a);
	stack_push_top(&state->b, top_node_a);
	op_print(state, "pb");
}
