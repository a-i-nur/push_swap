/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:19 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:21 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sort stack A when it has exactly 2 elements.
 *
 * If the top index is larger than the next, swap them.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	sort_small_2(t_state *state)
{
	if (state->a.top->index > state->a.top->next->index)
		op_sa(state);
}

/**
 * @brief Sort stack A when it has exactly 3 elements.
 *
 * It checks the order of top, middle, bottom indexes and applies
 * the minimal sequence of operations.
 *
 * @param state Global state.
 * @return Nothing.
 */
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

/**
 * @brief Sort stack A when it has exactly 4 elements.
 *
 * Steps:
 * 1) Move the smallest index to top.
 * 2) Push it to B.
 * 3) Sort the remaining 3 in A.
 * 4) Push back from B to A.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	sort_small_4(t_state *state)
{
	int	pos;

	pos = find_min_pos(&state->a);
	bring_pos_to_top(state, pos, 'a');
	op_pb(state);
	sort_small_3(state);
	op_pa(state);
}

/**
 * @brief Sort stack A when it has exactly 5 elements.
 *
 * Steps:
 * 1) Repeat twice: move min to top and push to B.
 * 2) Sort remaining 3 in A.
 * 3) If needed, swap B to keep its order.
 * 4) Push both back to A.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	sort_small_5(t_state *state)
{
	int	pos;
	int	i;

	i = 0;
	while (i < 2)
	{
		pos = find_min_pos(&state->a);
		bring_pos_to_top(state, pos, 'a');
		op_pb(state);
		i++;
	}
	sort_small_3(state);
	if (state->b.top->index < state->b.top->next->index)
		op_sb(state);
	op_pa(state);
	op_pa(state);
}

/**
 * @brief Dispatch small sort based on stack A size.
 *
 * It selects a specialized routine for size 2..5.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	sort_small(t_state *state)
{
	int	size;

	size = state->a.size;
	if (size <= 1)
		return ;
	if (size == 2)
		sort_small_2(state);
	else if (size == 3)
		sort_small_3(state);
	else if (size == 4)
		sort_small_4(state);
	else if (size == 5)
		sort_small_5(state);
}
