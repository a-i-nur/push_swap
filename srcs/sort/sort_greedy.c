#include "push_swap.h"

static void	apply_dual_rotation_next(t_state *state, int *rot_a, int *rot_b)
{
	while (*rot_a < 0)
	{
		op_rra(state);
		(*rot_a)++;
	}
	while (*rot_b > 0)
	{
		op_rb(state);
		(*rot_b)--;
	}
	while (*rot_b < 0)
	{
		op_rrb(state);
		(*rot_b)++;
	}
}

/**
 * @brief Применить совместные и одиночные вращения A/B.
 * @param st Состояние.
 * @param rot_a Вращения A.
 * @param rot_b Вращения B.
 */
static void	apply_dual_rotations(t_state *state, int rot_a, int rot_b)
{
	while (rot_a > 0 && rot_b > 0)
	{
		op_rr(state);
		rot_a--;
		rot_b--;
	}
	while (rot_a < 0 && rot_b < 0)
	{
		op_rrr(state);
		rot_a++;
		rot_b++;
	}
	while (rot_a > 0)
	{
		op_ra(state);
		rot_a--;
	}
	apply_dual_rotation_next(state, &rot_a, &rot_b);
}

static void	fill_best_move(t_state *state, t_move *best,
			t_node *node, int pos_b)
{
	int	x;
	int	target_pos_a;
	int	rot_a;
	int	rot_b;
	int	cost;

	x = node->index;
	target_pos_a = find_pos_by_index(&state->a,
			find_target_index_in_a(&state->a, x));
	rot_a = rotations_to_top(state->a.size, target_pos_a);
	rot_b = rotations_to_top(state->b.size, pos_b);
	cost = total_cost(rot_a, rot_b);
	if (cost < best->cost)
	{
		best->pos_b = pos_b;
		best->rot_a = rot_a;
		best->rot_b = rot_b;
		best->cost = cost;
	}
}

/**
 * @brief Выбрать элемент из B с минимальной ценой вставки в A.
 * @param state Состояние.
 * @return Структура t_move с лучшим вариантом.
 */
static t_move	pick_best_move_from_b(t_state *state)
{
	t_move	best;
	t_node	*node;
	int		pos_b;

	best.cost = INT_MAX;
	pos_b = 0;
	node = state->b.top;
	while (node)
	{
		fill_best_move(state, &best, node, pos_b);
		pos_b++;
		node = node->next;
	}
	return (best);
}

/**
 * @brief Жадно вернуть элементы из B в A по минимальной цене.
 * @param state Состояние.
 */
void	push_back_b_to_a_greedy(t_state *state)
{
	t_move	move;

	while (state->b.size > 0)
	{
		move = pick_best_move_from_b(state);
		apply_dual_rotations(state, move.rot_a, move.rot_b);
		op_pa(state);
	}
}
