/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:47:28 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:47:29 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Create a new state with empty stacks.
 *
 * It initializes stacks A and B, enables printing, and resets counters.
 *
 * @return Initialized t_state.
 */
t_state	state_new(void)
{
	t_state	state;

	state.a = stack_new('a');
	state.b = stack_new('b');
	state.print = 1;
	state.ops_count = 0;
	return (state);
}
