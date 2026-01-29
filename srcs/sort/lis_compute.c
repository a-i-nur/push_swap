/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:42 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:43 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Fill an array with indexes that are NOT in LIS.
 *
 * Iterates over flags and stores positions where flags[i] == 0.
 *
 * @param lis LIS helper struct with flags.
 * @param size Total size.
 * @param non_lis Output array for non-LIS indexes.
 * @return Nothing.
 */
static void	fill_non_lis_i(t_lis *lis, int size, int *non_lis)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (lis->flags[i] == 0)
		{
			non_lis[j] = i;
			j++;
		}
		i++;
	}
}

/**
 * @brief Mark the best LIS path and count non-LIS elements.
 *
 * It finds the best end, walks back using prev links,
 * sets flags to 1 for LIS, then counts the rest.
 *
 * @param lis LIS helper struct.
 * @param size Total size.
 * @return Nothing.
 */
static void	fill_lis_best(t_lis *lis, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (lis->len[i] > lis->best_len)
		{
			lis->best_len = lis->len[i];
			lis->best_index = i;
		}
		i++;
	}
	while (lis->best_index != -1)
	{
		lis->flags[lis->arr_index[lis->best_index]] = 1;
		lis->best_index = lis->prev[lis->best_index];
	}
	i = 0;
	while (i < size)
	{
		if (lis->flags[i] == 0)
			lis->count_non++;
		i++;
	}
}

/**
 * @brief Compute LIS lengths and prev links using DP.
 *
 * It copies node indexes to an array, then for each i, scans all j < i.
 *
 * @param lis LIS helper struct.
 * @param size Total size.
 * @return Nothing.
 */
static void	fill_lis_len(t_lis *lis, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		lis->arr_index[i++] = lis->node->index;
		lis->node = lis->node->next;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (lis->arr_index[j] < lis->arr_index[i]
				&& lis->len[j] + 1 > lis->len[i])
			{
				lis->len[i] = lis->len[j] + 1;
				lis->prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Compute LIS flags and the pivot of non-LIS indexes.
 *
 * LIS means "longest increasing subsequence".
 * pivot is the middle (median) index among non-LIS elements.
 *
 * @param a Stack A.
 * @param size Size of stack A.
 * @param pivot_out Output pivot (median of non-LIS, or -1 if none).
 * @return Flags array (1 = in LIS, 0 = not), or NULL on failure.
 */
int	*compute_lis_flags(const t_stack *a, int size, int *pivot_out)
{
	t_lis	lis;
	int		*non_lis;

	lis = lis_new(a, size);
	if (!lis.arr_index)
		return (NULL);
	fill_lis_len(&lis, size);
	fill_lis_best(&lis, size);
	if (lis.count_non == 0)
	{
		*pivot_out = -1;
		return (lis_free(&lis, 0), lis.flags);
	}
	non_lis = (int *)malloc(sizeof(int) * lis.count_non);
	if (!non_lis)
		return (lis_free(&lis, 1), NULL);
	fill_non_lis_i(&lis, size, non_lis);
	ft_merge_sort_ints(non_lis, 0, lis.count_non);
	*pivot_out = non_lis[lis.count_non / 2];
	free(non_lis);
	return (lis_free(&lis, 0), lis.flags);
}
