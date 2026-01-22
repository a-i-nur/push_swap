#include "push_swap.h"

int	find_min_pos(const t_stack *a)
{
	int	pos;
	int min_pos;
	int min_index;
	t_node *node;

	pos = 0;
	min_pos = 0;
	min_index = INT_MAX;
	node = a->top;
	while (node)
	{
		if (node->index < min_index)
		{
			min_index = node->index;
			min_pos = pos;
		}
		pos++;
		node = node->next;
	}
	return min_pos;
}

void	bring_pos_to_top_a(t_state *state, int pos)
{
	int	size; 

	size = state->a.size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			op_ra(state);
			pos--;
		}	
	} 
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			op_rra(state);
			pos--;
		}
	}
} 