/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:49 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:47 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finish remaining single rotations for A and B.
 *
 * Each loop performs one rotation until both counters reach zero.
 *
 * rotation means moving the top element (ra/rb) or bottom element (rra/rrb).
 *
 * @param state Global state.
 * @param rot_a Remaining rotations for A (will be updated to 0).
 * @param rot_b Remaining rotations for B (will be updated to 0).
 * @return Nothing.
 */
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
 * @brief Apply combined rotations, then single rotations, for A and B.
 *
 * Iteration order:
 * 1) Do rr or rrr while both rotations share direction.
 * 2) Finish remaining rotations on A.
 * 3) Finish remaining rotations on B.
 *
 * @param state Global state.
 * @param rot_a Rotations for A (signed).
 * @param rot_b Rotations for B (signed).
 * @return Nothing.
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

/**
 * @brief Update the best move if this node is cheaper to insert.
 *
 * It computes target position in A, rotation counts for both stacks,
 * then total cost. If cheaper, it overwrites best.
 *
 * @param state Global state.
 * @param best Current best move (updated in place).
 * @param node Current node from stack B.
 * @param pos_b Position of node in B (0 = top).
 * @return Nothing.
 */
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
 * @brief Choose the cheapest element from B to insert into A.
 *
 * Iterates all nodes in B and keeps the smallest cost move.
 *
 * @param state Global state.
 * @return t_move with the best rotations and position.
 */
static t_move	select_best_move_from_b(t_state *state)
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
 * @brief Greedily push all elements from B back to A.
 *
 * Each loop picks the cheapest move, applies rotations, then pushes.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	push_back_b_to_a_greedy(t_state *state)
{
	t_move	move;

	while (state->b.size > 0)
	{
		move = select_best_move_from_b(state);
		apply_dual_rotations(state, move.rot_a, move.rot_b);
		op_pa(state);
	}
}
