/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:53 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:54 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Find the position of a node by its index value.
 *
 * Iterates from the top until the index is found.
 *
 * index means the sorted position of a value (0..n-1).
 *
 * @param stack Stack to search.
 * @param index Target index value.
 * @return Position (0 = top), or -1 if not found.
 */
int	find_pos_by_index(const t_stack *stack, int index)
{
	int		pos;
	t_node	*node;

	pos = 0;
	node = stack->top;
	while (node)
	{
		if (node->index == index)
			return (pos);
		pos++;
		node = node->next;
	}
	return (-1);
}

/**
 * @brief Choose the index in A where index x should be inserted.
 *
 * Iterates over A to find the smallest index greater than x.
 * If none exists, it returns the minimum index in A.
 *
 * @param a Stack A.
 * @param x Index to insert.
 * @return Target index in A.
 */
int	find_target_index_in_a(const t_stack *a, int x)
{
	int		min_index;
	int		target;
	t_node	*node;

	min_index = INT_MAX;
	target = INT_MAX;
	node = a->top;
	while (node)
	{
		if (node->index < min_index)
			min_index = node->index;
		if (node->index > x && node->index < target)
			target = node->index;
		node = node->next;
	}
	if (target != INT_MAX)
		return (target);
	return (min_index);
}

/**
 * @brief Compute signed rotations needed to bring a position to the top.
 *
 * Positive means rotate forward (ra/rb), negative means reverse (rra/rrb).
 *
 * @param size Stack size.
 * @param pos Position of the element.
 * @return Signed rotation count.
 */
int	rotations_to_top(int size, int pos)
{
	int	rot;

	rot = 0;
	if (pos <= size / 2)
		rot = pos;
	else
		rot = -(size - pos);
	return (rot);
}

/**
 * @brief Get the absolute value of an int.
 *
 * @param x Input value.
 * @return Absolute value.
 */
static int	abs_i(int x)
{
	int	res;

	res = x;
	if (res < 0)
		res = -res;
	return (res);
}

/**
 * @brief Compute total cost of rotations for A and B.
 *
 * If both rotations are in the same direction, rr/rrr can combine them.
 *
 * @param rot_a Rotations for A.
 * @param rot_b Rotations for B.
 * @return Operation count cost.
 */
int	total_cost(int rot_a, int rot_b)
{
	int	abs_a;
	int	abs_b;
	int	max;
	int	sum;

	abs_a = abs_i(rot_a);
	abs_b = abs_i(rot_b);
	if ((rot_a >= 0 && rot_b >= 0) || (rot_a <= 0 && rot_b <= 0))
	{
		max = abs_a;
		if (abs_b > max)
			max = abs_b;
		return (max);
	}
	sum = abs_a + abs_b;
	return (sum);
}
