/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:23 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:24 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Choose small or big sort based on size of stack A.
 *
 * It checks size once, then calls the right routine.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	sort_dispatch(t_state *state)
{
	if (state->a.size <= SMALL_SORT_MAX)
		sort_small(state);
	else
		sort_big(state);
}
