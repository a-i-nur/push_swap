/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:49:23 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:49:24 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Print an operation and count it.
 *
 * If printing is disabled or inputs are invalid, it does nothing.
 *
 * @param state Global state (holds print flag and ops_count).
 * @param op Operation name like "sa".
 * @return Nothing.
 */
void	op_print(t_state *state, const char *op)
{
	int	res_printf;

	if (!state || !op || state->print == 0)
		return ;
	res_printf = ft_printf("%s\n", op);
	if (res_printf < 0)
		error_exit(state);
	state->ops_count++;
}
