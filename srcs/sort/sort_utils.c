#include "push_swap.h"

int	find_min_pos(const t_stack *stack)
{
	int	pos;
	int min_pos;
	int min_index;
	t_node *node;

	if (!stack || stack->size == 0 || !stack->top)
		return -1;
	pos = 0;
	min_pos = 0;
	min_index = INT_MAX;
	node = stack->top;
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

int find_max_pos(const t_stack *stack)
{
    int pos;
    int max_pos;
    int max_index;
    t_node *node;

	if (!stack || stack->size == 0 || !stack->top)
		return -1;
	pos = 0;
    max_pos = 0;
    max_index = INT_MIN;
    node = stack->top;
    while (node)
    {
        if (node->index > max_index)
        {
            max_index = node->index;
            max_pos = pos;
        }
        pos++;
        node = node->next;
    }
    return max_pos;
}

void	bring_pos_to_top(t_state *state, int pos, char stack_name)
{
	int	size; 

	if (!state || (stack_name != 'a' && stack_name != 'b'))
		return;
	if (stack_name == 'a')
		size = state->a.size;
	else if (stack_name == 'b')
		size = state->b.size;
	if (size <= 0 || pos < 0 || pos >= size)
		return;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			if (stack_name == 'a')
				op_ra(state);
			else if (stack_name == 'b')
				op_rb(state);
	} 
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			if (stack_name == 'a')
				op_rra(state);
			else if (stack_name == 'b')
				op_rrb(state);
	}
} 

int find_pos_in_chunk(const t_stack *stack, int low, int high)
{
    int pos;
    t_node *node;

	pos = 0;
    node = stack->top;
    while (node)
    {
        if (node->index >= low && node->index <= high)
            return (pos);
        pos++;
        node = node->next;
    }
    return (-1);
}

int	find_nearest_pos_in_range(const t_stack *stack, int low, int high)
{
	int		pos_front;
	int		pos_back;
	t_node	*node;

	if (!stack || stack->size == 0 || !stack->top)
		return (-1);
	pos_front = 0;
	node = stack->top;
	while (node)
	{
		if (node->index >= low && node->index <= high)
			break ;
		pos_front++;
		node = node->next;
	}
	if (!node)
		return (-1);
	pos_back = 0;
	node = stack->bottom;
	while (node)
	{
		if (node->index >= low && node->index <= high)
			break ;
		pos_back++;
		node = node->prev;
	}
	if (pos_front <= pos_back)
		return (pos_front);
	return (stack->size - pos_back);
}

int find_insert_pos_in_a(const t_stack *a, int x)
{
	int		pos;
	int		min_pos;
	int		min_index;
	int		max_index;
	t_node	*node;

	if (!a || a->size == 0 || !a->top)
		return (0);
	pos = 0;
	min_pos = 0;
	min_index = INT_MAX;
	max_index = INT_MIN;
	node = a->top;
	while (node)
	{
		if (node->index < min_index)
		{
			min_index = node->index;
			min_pos = pos;
		}
		if (node->index > max_index)
			max_index = node->index;
		pos++;
		node = node->next;
	}
	if (x < min_index || x > max_index)
		return (min_pos);
	pos = 0;
	node = a->top;
	while (node && node->next)
	{
		if (node->index < x && node->next->index > x)
			return (pos + 1);
		pos++;
		node = node->next;
	}
	return (0);
}

static int	find_nearest_below_pos(const t_stack *stack, int limit)
{
	int		pos;
	int		pos_front;
	int		pos_back;
	t_node	*node;

	if (!stack || stack->size == 0 || !stack->top)
		return (-1);
	pos_front = 0;
	node = stack->top;
	while (node)
	{
		if (node->index < limit)
			break ;
		pos_front++;
		node = node->next;
	}
	if (!node)
		return (-1);
	pos_back = 0;
	node = stack->bottom;
	while (node)
	{
		if (node->index < limit)
			break ;
		pos_back++;
		node = node->prev;
	}
	if (pos_front <= pos_back)
		return (pos_front);
	pos = stack->size - pos_back;
	return (pos);
}

int choose_chunk_count(int n)
{
	if (n <= 100)
		return (8);
	if (n <= 500)
		return (16);
	return (20);
}

void push_chunks_a_to_b(t_state *state)
{
	int		size;
	int		limit;
	int		pos;

	size = state->a.size;
	while (state->a.size > 3)
	{
		limit = size - (state->a.size * 4) / 5;
		if (limit > size - 3)
			limit = size - 3;
		if (state->a.top->index < limit)
			op_pb(state);
		else
		{
			pos = find_nearest_below_pos(&state->a, limit);
			if (pos < 0)
				break ;
			bring_pos_to_top(state, pos, 'a');
			if (state->a.top->index < limit)
				op_pb(state);
		}
	}
}

int rotations_to_top(int size, int pos)
{
	int	rot;

	rot = 0;
	if (pos <= size / 2)
		rot = pos;
	else
		rot = -(size - pos);
	return (rot);
}

int	abs_i(int x)
{
	int	res;

	res = x;
	if (res < 0)
		res = -res;
	return (res);
}

int total_cost(int rot_a, int rot_b)
{
	int	abs_a;
	int	abs_b;
	int	max;
	int	sum;

	abs_a = abs_i(rot_a);
	abs_b = abs_i(rot_b);
	if ((rot_a >= 0 && rot_b >= 0) || (rot_a <= 0 && rot_b <= 0))
	{
		max = abs_a;
		if (abs_b > max)
			max = abs_b;
		return (max);
	}
	sum = abs_a + abs_b;
	return (sum);
}

t_move pick_best_move_from_b(t_state *st)
{
	t_move	best;
	t_node	*node;
	int		pos_b;
	int		x;
	int		target_pos_a;
	int		rot_a;
	int		rot_b;
	int		cost;

	best.cost = INT_MAX;
	pos_b = 0;
	node = st->b.top;
	while (node)
	{
		x = node->index;

		target_pos_a = find_insert_pos_in_a(&st->a, x);

		rot_a = rotations_to_top(st->a.size, target_pos_a);
		rot_b = rotations_to_top(st->b.size, pos_b);

		cost = total_cost(rot_a, rot_b);

		if (cost < best.cost)
		{
			best.pos_b = pos_b;
			best.rot_a = rot_a;
			best.rot_b = rot_b;
			best.cost = cost;
		}
		pos_b++;
		node = node->next;
	}
	return (best);
}

void apply_dual_rotations(t_state *st, int rot_a, int rot_b)
{
	while (rot_a > 0 && rot_b > 0)
	{
		op_rr(st);
		rot_a--;
		rot_b--;
	}
	while (rot_a < 0 && rot_b < 0)
	{
		op_rrr(st);
		rot_a++;
		rot_b++;
	}
	while (rot_a > 0)
	{
		op_ra(st);
		rot_a--;
	}
	while (rot_a < 0)
	{
		op_rra(st);
		rot_a++;
	}
	while (rot_b > 0)
	{
		op_rb(st);
		rot_b--;
	}
	while (rot_b < 0)
	{
		op_rrb(st);
		rot_b++;
	}
}

void push_back_b_to_a_greedy(t_state *st)
{
	t_move	mv;

	while (st->b.size > 0)
	{
		mv = pick_best_move_from_b(st);
		apply_dual_rotations(st, mv.rot_a, mv.rot_b);
		op_pa(st);
	}
}

void final_rotate_min_to_top(t_state *st)
{
	int	pos_min;

	pos_min = find_min_pos(&st->a);
	bring_pos_to_top(st, pos_min, 'a');
}
