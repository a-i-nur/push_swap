/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:31 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:32 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Move from stack A to stack B all nodes that are not in LIS.
 *
 * LIS means "longest increasing subsequence" of node indexes in stack order.
 * Step by step:
 * 1) Build LIS flags for indexes in A.
 * 2) Iterate over all nodes in A (exactly size times).
 * 3) If a node is in LIS, rotate A to keep it.
 * 4) Otherwise push it to B, and maybe rotate B if its index is above pivot.
 *
 * pivot is the middle (median) index among non-LIS nodes.
 *
 * @param state Global state with stacks A and B.
 * @return Nothing.
 */
void	push_chunks_a_to_b(t_state *state)
{
	int	size;
	int	i;
	int	*flags;
	int	pivot;

	size = state->a.size;
	if (size <= 3)
		return ;
	pivot = -1;
	flags = compute_lis_flags(&state->a, size, &pivot);
	if (!flags)
		error_exit(state);
	i = 0;
	while (i++ < size)
	{
		if (flags[state->a.top->index] == 1)
			op_ra(state);
		else
		{
			op_pb(state);
			if (pivot >= 0 && state->b.top->index > pivot)
				op_rb(state);
		}
	}
	free(flags);
}
