/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:47:03 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/30 12:40:18 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Program entry point.
 *
 * Steps:
 * 1) Initialize state.
 * 2) Parse arguments into stack A.
 * 3) If already sorted, free and exit.
 * 4) Assign indexes and sort.
 * 5) Free state and exit.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return 0 on normal exit.
 */
int	main(int argc, char *argv[])
{
	t_state	state;

	state = state_new();
	parse_args(&state, argc, argv);
	if (is_sorted_stack(&state.a))
	{
		state_free(&state);
		return (0);
	}
	if (assign_indexes(&state.a) == 0)
		error_exit(&state);
	sort_dispatch(&state);
	state_free(&state);
	return (0);
}
