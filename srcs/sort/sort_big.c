#include "push_swap.h"

// static int max_bits(int size)
// {
// 	int bits = 0;
// 	int max = size - 1;
// 	while ((max >> bits) != 0)
// 		bits++;
// 	return bits;
// }


// void sort_big(t_state *state)
// {
// 	int bits;
// 	int count;
// 	int bit;
// 	int i;

// 	bits = max_bits(state->a.size);
// 	bit = 0;
// 	while (bit < bits)
// 	{
// 		count = state->a.size;
// 		i = 0;
// 		while (i < count)
// 		{
// 			if (((state->a.top->index >> bit) & 1) == 0)
// 				op_pb(state);
// 			else
// 				op_ra(state);
// 			i++;
// 		}
// 		while (state->b.size > 0)
// 			op_pa(state);
// 		bit++;
// 	}
// }

/**
 * @brief Основная сортировка для больших размеров.
 *
 * Алгоритм:
 * 1) Вытолкнуть все элементы, не входящие в LIS, из A в B.
 * 2) Отсортировать оставшиеся 3 элемента в A.
 * 3) Вернуть элементы из B в A жадно по минимальной цене.
 * 4) Довернуть A так, чтобы минимум был сверху.
 *
 * @param state Состояние.
 */
void sort_big(t_state *state)
{
	push_chunks_a_to_b(state);
	sort_small_3(state);
	push_back_b_to_a_greedy(state);
	final_rotate_min_to_top(state);
}
