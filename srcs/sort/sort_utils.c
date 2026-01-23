#include "push_swap.h"

/**
 * @brief Найти позицию минимального индекса в стеке.
 * @param stack Стек для поиска.
 * @return Позиция (0 = верх) или -1 при пустом/NULL.
 */
int	find_min_pos(const t_stack *stack)
{
	int	pos;
	int min_pos;
	int min_index;
	t_node *node;

	if (!stack || stack->size == 0 || !stack->top)
		return -1;
	pos = 0;
	min_pos = 0;
	min_index = INT_MAX;
	node = stack->top;
	while (node)
	{
		if (node->index < min_index)
		{
			min_index = node->index;
			min_pos = pos;
		}
		pos++;
		node = node->next;
	}
	return min_pos;
}

/**
 * @brief Найти позицию максимального индекса в стеке.
 * @param stack Стек для поиска.
 * @return Позиция (0 = верх) или -1 при пустом/NULL.
 */
int find_max_pos(const t_stack *stack)
{
    int pos;
    int max_pos;
    int max_index;
    t_node *node;

	if (!stack || stack->size == 0 || !stack->top)
		return -1;
	pos = 0;
    max_pos = 0;
    max_index = INT_MIN;
    node = stack->top;
    while (node)
    {
        if (node->index > max_index)
        {
            max_index = node->index;
            max_pos = pos;
        }
        pos++;
        node = node->next;
    }
    return max_pos;
}

/**
 * @brief Прокрутить стек так, чтобы элемент по позиции стал сверху.
 * @param state Состояние.
 * @param pos Позиция (0 = верх).
 * @param stack_name 'a' или 'b'.
 */
void	bring_pos_to_top(t_state *state, int pos, char stack_name)
{
	int	size; 

	if (!state || (stack_name != 'a' && stack_name != 'b'))
		return;
	if (stack_name == 'a')
		size = state->a.size;
	else if (stack_name == 'b')
		size = state->b.size;
	if (size <= 0 || pos < 0 || pos >= size)
		return;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			if (stack_name == 'a')
				op_ra(state);
			else if (stack_name == 'b')
				op_rb(state);
	} 
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			if (stack_name == 'a')
				op_rra(state);
			else if (stack_name == 'b')
				op_rrb(state);
	}
} 





/**
 * @brief Найти позицию элемента по индексу в стеке.
 * @param stack Стек.
 * @param idx Искомый индекс.
 * @return Позиция (0 = верх), 0 если не найден.
 */
static int	find_pos_by_index(const t_stack *stack, int idx)
{
	int		pos;
	t_node	*node;

	pos = 0;
	node = stack->top;
	while (node)
	{
		if (node->index == idx)
			return (pos);
		pos++;
		node = node->next;
	}
	return (0);
}

/**
 * @brief Найти целевой индекс в A для вставки x.
 *
 * Ищем минимальный индекс больше x. Если такого нет, берём минимальный индекс.
 *
 * @param a Стек A.
 * @param x Индекс из B.
 * @return Целевой индекс в A.
 */
static int	find_target_index_in_a(const t_stack *a, int x)
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
int rotations_to_top(int size, int pos)
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
int	abs_i(int x)
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
int total_cost(int rot_a, int rot_b)
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

/**
 * @brief Выбрать элемент из B с минимальной ценой вставки в A.
 * @param st Состояние.
 * @return Структура t_move с лучшим вариантом.
 */
t_move pick_best_move_from_b(t_state *st)
{
	t_move	best;
	t_node	*node;
	int		pos_b;
	int		x;
	int		target_pos_a;
	int		rot_a;
	int		rot_b;
	int		cost;

	best.cost = INT_MAX;
	pos_b = 0;
	node = st->b.top;
	while (node)
	{
		x = node->index;

		target_pos_a = find_pos_by_index(&st->a,
				find_target_index_in_a(&st->a, x));
		rot_a = rotations_to_top(st->a.size, target_pos_a);
		rot_b = rotations_to_top(st->b.size, pos_b);

		cost = total_cost(rot_a, rot_b);

		if (cost < best.cost)
		{
			best.pos_b = pos_b;
			best.rot_a = rot_a;
			best.rot_b = rot_b;
			best.cost = cost;
		}
		pos_b++;
		node = node->next;
	}
	return (best);
}

/**
 * @brief Применить совместные и одиночные вращения A/B.
 * @param st Состояние.
 * @param rot_a Вращения A.
 * @param rot_b Вращения B.
 */
void apply_dual_rotations(t_state *st, int rot_a, int rot_b)
{
	while (rot_a > 0 && rot_b > 0)
	{
		op_rr(st);
		rot_a--;
		rot_b--;
	}
	while (rot_a < 0 && rot_b < 0)
	{
		op_rrr(st);
		rot_a++;
		rot_b++;
	}
	while (rot_a > 0)
	{
		op_ra(st);
		rot_a--;
	}
	while (rot_a < 0)
	{
		op_rra(st);
		rot_a++;
	}
	while (rot_b > 0)
	{
		op_rb(st);
		rot_b--;
	}
	while (rot_b < 0)
	{
		op_rrb(st);
		rot_b++;
	}
}

/**
 * @brief Жадно вернуть элементы из B в A по минимальной цене.
 * @param st Состояние.
 */
void push_back_b_to_a_greedy(t_state *st)
{
	t_move	mv;

	while (st->b.size > 0)
	{
		mv = pick_best_move_from_b(st);
		apply_dual_rotations(st, mv.rot_a, mv.rot_b);
		op_pa(st);
	}
}

/**
 * @brief Довернуть A так, чтобы минимальный индекс был сверху.
 * @param st Состояние.
 */
void final_rotate_min_to_top(t_state *st)
{
	int	pos_min;

	pos_min = find_min_pos(&st->a);
	bring_pos_to_top(st, pos_min, 'a');
}
