/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:07 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:08 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Copy node values into an array in stack order.
 *
 * Iterates from current node to the end of the list.
 *
 * @param arr_values Output array.
 * @param node Start node (usually stack top).
 * @return Nothing.
 */
static void	copy_values(int *arr_values, t_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		arr_values[i] = node->value;
		i++;
		node = node->next;
	}
}

/**
 * @brief Assign sorted indexes to each node in stack A.
 *
 * Steps:
 * 1) Copy values into an array.
 * 2) Sort the array.
 * 3) For each node, find its position in the sorted array.
 *
 * index means the sorted position of a value (0..n-1).
 *
 * @param a Stack A.
 * @return 1 on success, 0 on failure.
 */
int	assign_indexes(t_stack *a)
{
	int		size_stack;
	int		*arr_values;
	t_node	*node;

	size_stack = a->size;
	if (size_stack <= 0)
		return (0);
	arr_values = (int *)malloc(size_stack * sizeof(int));
	if (!arr_values)
		return (0);
	node = a->top;
	copy_values(arr_values, node);
	if (ft_merge_sort_ints(arr_values, 0, size_stack) == 0)
	{
		free(arr_values);
		return (0);
	}
	node = a->top;
	while (node != NULL)
	{
		node->index = find_index(arr_values, size_stack, node->value);
		node = node->next;
	}
	free(arr_values);
	return (1);
}
