/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:49:10 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:49:11 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap the top two elements of stack A and print "sa".
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_sa(t_state *state)
{
	if (!state || state->a.size < 2)
		return ;
	stack_swap_top(&state->a);
	op_print(state, "sa");
}

/**
 * @brief Swap the top two elements of stack B and print "sb".
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_sb(t_state *state)
{
	if (!state || state->b.size < 2)
		return ;
	stack_swap_top(&state->b);
	op_print(state, "sb");
}

/**
 * @brief Swap top two elements of both stacks and print "ss".
 *
 * It calls op_sa and op_sb with printing disabled, then prints once.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	op_ss(t_state *state)
{
	int	save_print;

	if (!state)
		return ;
	save_print = state->print;
	state->print = 0;
	op_sa(state);
	op_sb(state);
	state->print = save_print;
	if (state->a.size >= 2 || state->b.size >= 2)
		op_print(state, "ss");
}
