/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:34 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:35 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Free all allocated arrays in a LIS helper struct.
 *
 * LIS means "longest increasing subsequence".
 *
 * @param lis LIS helper struct.
 * @param with_flags If 1, also free flags array.
 * @return Nothing.
 */
void	lis_free(t_lis *lis, int with_flags)
{
	if (lis->arr_index)
		free(lis->arr_index);
	if (lis->len)
		free(lis->len);
	if (lis->prev)
		free(lis->prev);
	if (with_flags)
	{
		if (lis->flags)
			free(lis->flags);
	}
}

/**
 * @brief Create and initialize a LIS helper struct for stack A.
 *
 * It allocates arrays and sets default values for each position.
 *
 * @param a Stack A.
 * @param size Size of stack A.
 * @return Initialized t_lis, or zeroed struct on allocation failure.
 */
t_lis	lis_new(const t_stack *a, int size)
{
	t_lis	lis;
	int		i;

	lis = (t_lis){0};
	lis.arr_index = (int *)malloc(size * sizeof(int));
	lis.len = (int *)malloc(size * sizeof(int));
	lis.prev = (int *)malloc(size * sizeof(int));
	lis.flags = (int *)malloc(size * sizeof(int));
	if (!lis.arr_index || !lis.len || !lis.prev || !lis.flags)
	{
		return (lis_free(&lis, 1), (t_lis){0});
	}
	i = 0;
	while (i < size)
	{
		lis.arr_index[i] = 0;
		lis.len[i] = 1;
		lis.prev[i] = -1;
		lis.flags[i] = 0;
		i++;
	}
	lis.node = a->top;
	lis.best_len = 0;
	lis.best_index = 0;
	return (lis.count_non = 0, lis);
}
