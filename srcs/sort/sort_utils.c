/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:18 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:19 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Find the position of the smallest index in a stack.
 *
 * Iterates from top to bottom and tracks the minimum index seen.
 *
 * index means the sorted position of a value (0..n-1).
 *
 * @param stack Stack to scan.
 * @return Position (0 = top) or -1 if stack is empty or NULL.
 */
int	find_min_pos(const t_stack *stack)
{
	int		pos;
	int		min_pos;
	int		min_index;
	t_node	*node;

	if (!stack || stack->size == 0 || !stack->top)
		return (-1);
	pos = 0;
	min_pos = 0;
	min_index = INT_MAX;
	node = stack->top;
	while (node)
	{
		if (node->index < min_index)
		{
			min_index = node->index;
			min_pos = pos;
		}
		pos++;
		node = node->next;
	}
	return (min_pos);
}

/**
 * @brief Find the position of the largest index in a stack.
 *
 * Iterates from top to bottom and tracks the maximum index seen.
 *
 * index means the sorted position of a value (0..n-1).
 *
 * @param stack Stack to scan.
 * @return Position (0 = top) or -1 if stack is empty or NULL.
 */
int	find_max_pos(const t_stack *stack)
{
	int		pos;
	int		max_pos;
	int		max_index;
	t_node	*node;

	if (!stack || stack->size == 0 || !stack->top)
		return (-1);
	pos = 0;
	max_pos = 0;
	max_index = INT_MIN;
	node = stack->top;
	while (node)
	{
		if (node->index > max_index)
		{
			max_index = node->index;
			max_pos = pos;
		}
		pos++;
		node = node->next;
	}
	return (max_pos);
}

/**
 * @brief Rotate one stack so a given position becomes the top.
 *
 * If the position is in the first half, rotate forward.
 * Otherwise rotate reverse. Each loop performs one rotation.
 *
 * @param state Global state.
 * @param pos Target position (0 = top).
 * @param size Current stack size.
 * @param stack_n Stack name: 'a' or 'b'.
 * @return Nothing.
 */
static void	rotate_pos_to_top(t_state *state, int pos, int size, char stack_n)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (stack_n == 'a')
				op_ra(state);
			else if (stack_n == 'b')
				op_rb(state);
		}
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
		{
			if (stack_n == 'a')
				op_rra(state);
			else if (stack_n == 'b')
				op_rrb(state);
		}
	}
}

/**
 * @brief Rotate a stack so the element at position becomes the top.
 *
 * This is a safe wrapper that checks inputs before rotating.
 *
 * @param state Global state.
 * @param pos Position (0 = top).
 * @param stack_name 'a' or 'b'.
 * @return Nothing.
 */
void	bring_pos_to_top(t_state *state, int pos, char stack_name)
{
	int	size;

	if (!state || (stack_name != 'a' && stack_name != 'b'))
		return ;
	if (stack_name == 'a')
		size = state->a.size;
	else if (stack_name == 'b')
		size = state->b.size;
	if (size <= 0 || pos < 0 || pos >= size)
		return ;
	rotate_pos_to_top(state, pos, size, stack_name);
}

/**
 * @brief Rotate stack A so the smallest index is on top.
 *
 * It finds the min position, then rotates A until it is on top.
 *
 * @param state Global state.
 * @return Nothing.
 */
void	final_rotate_min_to_top(t_state *state)
{
	int	pos_min;

	pos_min = find_min_pos(&state->a);
	bring_pos_to_top(state, pos_min, 'a');
}
