/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:49:19 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:49:20 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Push the top of stack B to stack A and print "pa".
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_pa(t_state *state)
{
	t_node	*top_node_b;

	if (!state || state->b.size == 0)
		return ;
	top_node_b = stack_pop_top(&state->b);
	stack_push_top(&state->a, top_node_b);
	op_print(state, "pa");
}

/**
 * @brief Push the top of stack A to stack B and print "pb".
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_pb(t_state *state)
{
	t_node	*top_node_a;

	if (!state || state->a.size == 0)
		return ;
	top_node_a = stack_pop_top(&state->a);
	stack_push_top(&state->b, top_node_a);
	op_print(state, "pb");
}
