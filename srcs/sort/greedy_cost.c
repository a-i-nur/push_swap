#include "push_swap.h"

int	find_pos_by_index(const t_stack *stack, int index)
{
	int		pos;
	t_node	*node;

	pos = 0;
	node = stack->top;
	while (node)
	{
		if (node->index == index)
			return (pos);
		pos++;
		node = node->next;
	}
	return (-1);
}

int	find_target_index_in_a(const t_stack *a, int x)
{
	int		min_index;
	int		target;
	t_node	*node;

	min_index = INT_MAX;
	target = INT_MAX;
	node = a->top;
	while (node)
	{
		if (node->index < min_index)
			min_index = node->index;
		if (node->index > x && node->index < target)
			target = node->index;
		node = node->next;
	}
	if (target != INT_MAX)
		return (target);
	return (min_index);
}

/**
 * @brief Посчитать вращения до верха (со знаком).
 * @param size Размер стека.
 * @param pos Позиция элемента.
 * @return + для ra/rb, - для rra/rrb.
 */
int	rotations_to_top(int size, int pos)
{
	int	rot;

	rot = 0;
	if (pos <= size / 2)
		rot = pos;
	else
		rot = -(size - pos);
	return (rot);
}

/**
 * @brief Абсолютное значение int.
 */
static int	abs_i(int x)
{
	int	res;

	res = x;
	if (res < 0)
		res = -res;
	return (res);
}

/**
 * @brief Общая стоимость вращений с учетом rr/rrr.
 * @param rot_a Вращения A.
 * @param rot_b Вращения B.
 * @return Количество операций.
 */
int	total_cost(int rot_a, int rot_b)
{
	int	abs_a;
	int	abs_b;
	int	max;
	int	sum;

	abs_a = abs_i(rot_a);
	abs_b = abs_i(rot_b);
	if ((rot_a >= 0 && rot_b >= 0) || (rot_a <= 0 && rot_b <= 0))
	{
		max = abs_a;
		if (abs_b > max)
			max = abs_b;
		return (max);
	}
	sum = abs_a + abs_b;
	return (sum);
}
