/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:49:14 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:49:15 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotate stack A (top goes to bottom) and print "ra".
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_ra(t_state *state)
{
	if (!state || state->a.size < 2)
		return ;
	stack_rotate(&state->a);
	op_print(state, "ra");
}

/**
 * @brief Rotate stack B (top goes to bottom) and print "rb".
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_rb(t_state *state)
{
	if (!state || state->b.size < 2)
		return ;
	stack_rotate(&state->b);
	op_print(state, "rb");
}

/**
 * @brief Rotate both stacks and print "rr".
 *
 * It calls op_ra and op_rb with printing disabled, then prints once.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_rr(t_state *state)
{
	int	save_print;

	if (!state)
		return ;
	save_print = state->print;
	state->print = 0;
	op_ra(state);
	op_rb(state);
	state->print = save_print;
	if (state->a.size >= 2 || state->b.size >= 2)
		op_print(state, "rr");
}
