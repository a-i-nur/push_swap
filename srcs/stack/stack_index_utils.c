#include "push_swap.h"

static void    merge_sorted_halves(int *arr, int *merge_arr, int left, int middle, int right)
{
	int i;
	int j;
	int k;

	i = left;
	j = middle;
	k = 0;
	while (i < middle && j < right)
	{
		if (arr[i] <= arr[j])
			merge_arr[k++] = arr[i++];
		else
			merge_arr[k++] = arr[j++];
	}
	while (i < middle)
		merge_arr[k++] = arr[i++];
	while (j < right)
		merge_arr[k++] = arr[j++];
}

static int merge_core(int *arr, int left, int middle, int right)
{
	int *merge_arr;
	int i;
	int k;
	merge_arr = (int *)malloc((right - left) * sizeof(int));
	if (!merge_arr)
		return (0);
	merge_sorted_halves(arr, merge_arr, left, middle, right);
	i = left;
	k = 0;
	while (i < right)
	{
		arr[i] = merge_arr[k];
		i++;
		k++;
	}
	free(merge_arr);
	merge_arr = 0;
	return (1);
}

int ft_merge_sort_ints(int *arr, int left, int right)
{
	int middle;

	if ((right - left) <= 1)
		return (1);
	middle = (left + right) / 2;
	if (ft_merge_sort_ints(arr, left, middle) == 0)
		return (0);
	if (ft_merge_sort_ints(arr, middle, right) == 0)
		return (0);
	if (merge_core(arr, left, middle, right) == 0)
		return (0);
	return (1);
}

int find_index(const int *arr, int size, int value)
{
	int left;
	int right;
	int middle;

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

int	is_sorted_stack(const t_stack *a)
{
	t_node	*node;

	if (!a)
		return (1);
	if (a->size <= 1)
		return (1);
	
	node = a->top;
	while(node->next != NULL)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}