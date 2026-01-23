#include "push_swap.h"


typedef struct	s_lis
{
	int		*arr_index;
	int		*len;
	int		*prev;
	int		*flags;
	int		best_len;
	int		best_index;
	int		count_non;
	t_node	*node;
} t_lis;

t_lis lis_new(const t_stack *a, int size)
{
	t_lis	lis;
	int		i;

	lis.arr_index = (int *)malloc(size * sizeof(int));
	lis.len = (int *)malloc(size * sizeof(int));
	lis.prev = (int *)malloc(size * sizeof(int));
	lis.flags = (int *)malloc(size * sizeof(int));
	if (!lis.arr_index || !lis.len || !lis.prev || !lis.flags)
	{
		lis_free(&lis, 1);
		return (NULL);
	}
	i = 0;
	while (i++ < size)
	{
		lis.arr_index[i] = 0;
		lis.len[i] = 1;
		lis.prev[i] = -1;
		lis.flags[i] = 0;
	}
	lis.node = a->top;
	lis.best_len = 0;
	lis.best_index = 0;
	list.count_non = 0;
	return (lis);
}

void lis_free(t_lis *lis, int with_flags)
{
	free(lis->arr_index);
	free(lis->len);
	free(lis->prev);
	if (with_flags)
		free(lis->flags);
}

/**
 * @brief Посчитать LIS-флаги и медиану non-LIS.
 * @param a Стек A.
 * @param size Размер.
 * @param pivot_out Выходной pivot (медиана non-LIS).
 * @return Массив flags (1 = в LIS) или NULL.
 */
static int	*compute_lis_flags_and_pivot(const t_stack *a, int size, int *pivot_out)
{
	int		i;
	int		j;
	t_lis	lis;
	int		*non_lis;

	lis = lis_new(a, size);
	if (!lis.arr_index)
		return (NULL);
	i = 0;
	while (i < size)
	{
		lis.arr_index[i] = lis.node->index;
		lis.node = lis.node->next;
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (lis.arr_index[j] < lis.arr_index[i] && lis.len[j] + 1 > lis.len[i])
			{
				lis.len[i] = lis.len[j] + 1;
				lis.prev[i] = j;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (lis.len[i] > lis.best_len)
		{
			lis.best_len = lis.len[i];
			lis.best_index = i;
		}
		i++;
	}
	while (lis.best_index != -1)
	{
		lis.flags[lis.arr_index[lis.best_index]] = 1;
		lis.best_index = lis.prev[lis.best_index];
	}
	i = 0;
	while (i < size)
	{
		if (lis.flags[i] == 0)
			lis.count_non++;
		i++;
	}
	if (lis.count_non == 0)
	{
		*pivot_out = -1;
		lis_free(&lis, 0);
		return (lis.flags);
	}
	non_lis = (int *)malloc(sizeof(int) * lis.count_non);
	if (!non_lis)
	{
		lis_free(&lis, 1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		if (flags[i] == 0)
		{
			non_lis[j] = i;
			j++;
		}
		i++;
	}
	ft_merge_sort_ints(non_lis, 0, lis.count_non);
	*pivot_out = non_lis[lis.count_non / 2];
	free(non_lis);
	lis_free(&lis, 0);
	return (lis.flags);
}

/**
 * @brief Переносить в B все элементы, не входящие в LIS.
 *
 * Алгоритм:
 * 1) Находим LIS по индексам (0..n-1) в порядке стека A.
 * 2) Все элементы, не входящие в LIS, отправляем в B.
 * 3) Дополнительно предсортируем B по медиане non_lis:
 *    большие индексы уводим вниз через rb.
 */
void push_chunks_a_to_b(t_state *state)
{
	int	size;
	int	i;
	int	*flags;
	int	pivot;

	size = state->a.size;
	if (size <= 3)
		return ;
	pivot = -1;
	flags = compute_lis_flags_and_pivot(&state->a, size, &pivot);
	if (!flags)
		return ;
	i = 0;
	while (i++ < size)
	{
		if (flags[state->a.top->index] == 1)
			op_ra(state);
		else
		{
			op_pb(state);
			if (pivot >= 0 && state->b.top->index > pivot)
				op_rb(state);
		}
	}
	free(flags);
}
