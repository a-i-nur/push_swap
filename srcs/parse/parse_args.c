#include "push_swap.h"

static int	check_duplicates(t_stack *a)
{
	t_node	*outer;
	t_node	*inner;

	if (!a || !a->top)
    	return (1);
	outer = a->top;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->value == inner->value)
				return (0);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (1);
}

static void	free_split(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

static void	parse_error(char **numbers, t_state *state)
{
	free_split(numbers);
	error_exit(state);
}

static void	parse_and_push_numbers(t_state *state, char **numbers)
{
	long	number;
	int		j;
	t_node	*node;
	int		num_int_flag;
	int		all_zero_flag;

	j = 0;
	while(numbers[j])
	{
		num_int_flag = 1;
		all_zero_flag = 0;
		if (is_valid_number(numbers[j], &all_zero_flag) == 0)
			parse_error(numbers, state);
		if (all_zero_flag == 1)
			number = 0;
		else
			number = ft_atol(numbers[j], &num_int_flag);
		if (num_int_flag == 0)
			parse_error(numbers, state);
		node = stack_node_new((int)number);
		if (!node)
			parse_error(numbers, state);
		stack_push_bottom(&state->a, node);
		j++;
	}
}

void	parse_args(t_state *state, int argc, char **argv)
{
	char	**numbers;
	int		i;

	if (!state || argc < 2)
		return ;
	i = 1;
	while (i < argc)
	{
		if (!argv[i])
			error_exit(state);
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			error_exit(state);
		if (!numbers[0])
			parse_error(numbers, state);
		parse_and_push_numbers(state, numbers);
		free_split(numbers);
		i++;
	}
	if (check_duplicates(&state->a) == 0)
		error_exit(state);
}
