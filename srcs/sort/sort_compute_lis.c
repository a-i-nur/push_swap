#include "push_swap.h"

/**
 * @brief Посчитать LIS-флаги и медиану non-LIS.
 * @param a Стек A.
 * @param size Размер.
 * @param pivot_out Выходной pivot (медиана non-LIS).
 * @return Массив flags (1 = в LIS) или NULL.
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

static void	fill_list_fap(t_lis *lis, int size)
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

static void	fill_lis_apl(t_lis *lis, int size)
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

int	*compute_lis_fap(const t_stack *a, int size, int *pivot_out)
{
	t_lis	lis;
	int		*non_lis;

	lis = lis_new(a, size);
	if (!lis.arr_index)
		return (NULL);
	fill_lis_apl(&lis, size);
	fill_list_fap(&lis, size);
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
