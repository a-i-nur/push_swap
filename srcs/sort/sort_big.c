#include "push_swap.h"

// static int max_bits(int size)
// {
// 	int bits = 0;
// 	int max = size - 1;
// 	while ((max >> bits) != 0)
// 		bits++;
// 	return bits;
// }


// void sort_big(t_state *state)
// {
// 	int bits;
// 	int count;
// 	int bit;
// 	int i;

// 	bits = max_bits(state->a.size);
// 	bit = 0;
// 	while (bit < bits)
// 	{
// 		count = state->a.size;
// 		i = 0;
// 		while (i < count)
// 		{
// 			if (((state->a.top->index >> bit) & 1) == 0)
// 				op_pb(state);
// 			else
// 				op_ra(state);
// 			i++;
// 		}
// 		while (state->b.size > 0)
// 			op_pa(state);
// 		bit++;
// 	}
// }

void sort_big(t_state *st)
{
	if (is_sorted_stack(&st->a))
		return;
	if (st->a.size <= 5)
	{
		sort_small(st);
		return;
	}
	push_chunks_a_to_b(st);
	sort_small_3(st);
	push_back_b_to_a_greedy(st);
	final_rotate_min_to_top(st);
}
