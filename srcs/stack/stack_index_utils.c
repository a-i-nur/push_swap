/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:10 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:11 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Merge two sorted halves into a temporary array.
 *
 * It iterates left and right pointers and writes in sorted order.
 *
 * @param arr Input array with two sorted halves.
 * @param merge_arr Output buffer.
 * @param vars Merge window (left, middle, right).
 * @return Nothing.
 */
static void	merge_sorted_halves(int *arr, int *merge_arr, t_mergevars *vars)
{
	int	i;
	int	j;
	int	k;

	i = vars->left;
	j = vars->middle;
	k = 0;
	while (i < vars->middle && j < vars->right)
	{
		if (arr[i] <= arr[j])
			merge_arr[k++] = arr[i++];
		else
			merge_arr[k++] = arr[j++];
	}
	while (i < vars->middle)
		merge_arr[k++] = arr[i++];
	while (j < vars->right)
		merge_arr[k++] = arr[j++];
}

/**
 * @brief Allocate buffer, merge halves, and copy back.
 *
 * @param arr Array to sort.
 * @param vars Merge window (left, middle, right).
 * @return 1 on success, 0 on allocation failure.
 */
static int	merge_core(int *arr, t_mergevars *vars)
{
	int	*merge_arr;
	int	i;
	int	k;

	merge_arr = (int *)malloc((vars->right - vars->left) * sizeof(int));
	if (!merge_arr)
		return (0);
	merge_sorted_halves(arr, merge_arr, vars);
	i = vars->left;
	k = 0;
	while (i < vars->right)
	{
		arr[i] = merge_arr[k];
		i++;
		k++;
	}
	free(merge_arr);
	merge_arr = 0;
	return (1);
}

/**
 * @brief Sort an int array using merge sort.
 *
 * Recursively splits the range [left, right) and merges.
 *
 * @param arr Array to sort.
 * @param left Left index (inclusive).
 * @param right Right index (exclusive).
 * @return 1 on success, 0 on allocation failure.
 */
int	ft_merge_sort_ints(int *arr, int left, int right)
{
	int			middle;
	t_mergevars	vars;

	if ((right - left) <= 1)
		return (1);
	middle = (left + right) / 2;
	if (ft_merge_sort_ints(arr, left, middle) == 0)
		return (0);
	if (ft_merge_sort_ints(arr, middle, right) == 0)
		return (0);
	vars.left = left;
	vars.middle = middle;
	vars.right = right;
	if (merge_core(arr, &vars) == 0)
		return (0);
	return (1);
}

/**
 * @brief Find the first position where value could be inserted.
 *
 * It uses binary search on a sorted array.
 *
 * @param arr Sorted array.
 * @param size Array size.
 * @param value Value to search.
 * @return Index where value is or should be.
 */
int	find_index(const int *arr, int size, int value)
{
	int	left;
	int	right;
	int	middle;

	left = 0;
	right = size;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (arr[middle] < value)
			left = middle + 1;
		else
			right = middle;
	}
	return (left);
}

/**
 * @brief Check if a stack is sorted in ascending order by value.
 *
 * Iterates from top to bottom and checks each adjacent pair.
 *
 * @param a Stack A.
 * @return 1 if sorted or empty, 0 otherwise.
 */
int	is_sorted_stack(const t_stack *a)
{
	t_node	*node;

	if (!a)
		return (1);
	if (a->size <= 1)
		return (1);
	node = a->top;
	while (node->next != NULL)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
