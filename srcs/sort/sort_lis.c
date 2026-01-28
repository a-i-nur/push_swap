#include "push_swap.h"

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
