/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:49:04 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:49:06 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check if stack A has duplicate values.
 *
 * Iterates with two loops (outer and inner) to compare each pair.
 *
 * @param a Stack A.
 * @return 1 if no duplicates, 0 if duplicate found.
 */
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

/**
 * @brief Free a NULL-terminated array of strings from ft_split.
 *
 * Iterates until NULL and frees each string and the array.
 *
 * @param numbers Array of strings.
 * @return Nothing.
 */
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

/**
 * @brief Handle parse error: free split array and exit with error.
 *
 * @param numbers Split array to free (may be partially filled).
 * @param state Global state.
 * @return Nothing (exits).
 */
static void	parse_error(char **numbers, t_state *state)
{
	free_split(numbers);
	error_exit(state);
}

/**
 * @brief Parse strings to integers and push into stack A.
 *
 * Iterates each string, validates it, converts to long,
 * checks int range, creates a node, then pushes to bottom of A.
 *
 * @param state Global state.
 * @param numbers NULL-terminated array of numeric strings.
 * @return Nothing.
 */
static void	parse_and_push_numbers(t_state *state, char **numbers)
{
	long	number;
	int		j;
	t_node	*node;
	int		num_int_flag;
	int		all_zero_flag;

	j = 0;
	while (numbers[j])
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

/**
 * @brief Parse argv and build stack A.
 *
 * Iterates over arguments, splits each by spaces, and pushes numbers.
 * Finally checks for duplicates.
 *
 * @param state Global state.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return Nothing.
 */
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
