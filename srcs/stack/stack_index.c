#include "push_swap.h"

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
