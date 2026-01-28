#include "push_swap.h"

/**
 * @brief Найти позицию минимального индекса в стеке.
 * @param stack Стек для поиска.
 * @return Позиция (0 = верх) или -1 при пустом/NULL.
 */
int	find_min_pos(const t_stack *stack)
{
	int		pos;
	int		min_pos;
	int		min_index;
	t_node	*node;

	if (!stack || stack->size == 0 || !stack->top)
		return (-1);
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
	return (min_pos);
}

/**
 * @brief Найти позицию максимального индекса в стеке.
 * @param stack Стек для поиска.
 * @return Позиция (0 = верх) или -1 при пустом/NULL.
 */
int	find_max_pos(const t_stack *stack)
{
	int		pos;
	int		max_pos;
	int		max_index;
	t_node	*node;

	if (!stack || stack->size == 0 || !stack->top)
		return (-1);
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
	return (max_pos);
}

static void	rotate_pos_to_top(t_state *state, int pos, int size, char stack_n)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (stack_n == 'a')
				op_ra(state);
			else if (stack_n == 'b')
				op_rb(state);
		}
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
		{
			if (stack_n == 'a')
				op_rra(state);
			else if (stack_n == 'b')
				op_rrb(state);
		}
	}
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
		return ;
	if (stack_name == 'a')
		size = state->a.size;
	else if (stack_name == 'b')
		size = state->b.size;
	if (size <= 0 || pos < 0 || pos >= size)
		return ;
	rotate_pos_to_top(state, pos, size, stack_name);
}

/**
 * @brief Довернуть A так, чтобы минимальный индекс был сверху.
 * @param st Состояние.
 */
void	final_rotate_min_to_top(t_state *st)
{
	int	pos_min;

	pos_min = find_min_pos(&st->a);
	bring_pos_to_top(st, pos_min, 'a');
}
