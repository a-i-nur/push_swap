/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:47:35 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:47:36 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Free a linked list of nodes.
 *
 * Iterates from the given node pointer until NULL.
 *
 * @param node Pointer to the head pointer.
 * @return Nothing.
 */
void	ft_stack_clear(t_node **node)
{
	t_node	*tmp;

	if (!node)
		return ;
	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		(*node) = tmp;
	}
	*node = NULL;
}

/**
 * @brief Free all nodes and reset state fields.
 *
 * It clears both stacks and zeros sizes and counters.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	state_free(t_state *state)
{
	if (!state)
		return ;
	ft_stack_clear(&state->a.top);
	ft_stack_clear(&state->b.top);
	state->a.top = NULL;
	state->a.bottom = NULL;
	state->a.size = 0;
	state->b.top = NULL;
	state->b.bottom = NULL;
	state->b.size = 0;
	state->ops_count = 0;
}
