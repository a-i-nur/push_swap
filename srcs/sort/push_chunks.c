#include "push_swap.h"

/**
 * @brief Переносить в B все элементы, не входящие в LIS.
 *
 * Алгоритм:
 * 1) Находим LIS по индексам (0..n-1) в порядке стека A.
 * 2) Все элементы, не входящие в LIS, отправляем в B.
 * 3) Дополнительно предсортируем B по медиане non_lis:
 *    большие индексы уводим вниз через rb.
 */
void	push_chunks_a_to_b(t_state *state)
{
	int	size;
	int	i;
	int	*flags;
	int	pivot;

	size = state->a.size;
	if (size <= 3)
		return ;
	pivot = -1;
	flags = compute_lis_flags(&state->a, size, &pivot);
	if (!flags)
		error_exit(state);
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
