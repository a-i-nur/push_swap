/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:49:15 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:49:16 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Reverse rotate stack A (bottom goes to top) and print "rra".
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_rra(t_state *state)
{
	if (!state || state->a.size < 2)
		return ;
	stack_reverse_rotate(&state->a);
	op_print(state, "rra");
}

/**
 * @brief Reverse rotate stack B (bottom goes to top) and print "rrb".
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_rrb(t_state *state)
{
	if (!state || state->b.size < 2)
		return ;
	stack_reverse_rotate(&state->b);
	op_print(state, "rrb");
}

/**
 * @brief Reverse rotate both stacks and print "rrr".
 *
 * It calls op_rra and op_rrb with printing disabled, then prints once.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_rrr(t_state *state)
{
	int	save_print;

	if (!state)
		return ;
	save_print = state->print;
	state->print = 0;
	op_rra(state);
	op_rrb(state);
	state->print = save_print;
	if (state->a.size >= 2 || state->b.size >= 2)
		op_print(state, "rrr");
}
