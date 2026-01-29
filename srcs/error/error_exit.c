/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:49:29 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:49:30 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Print error, free state, and exit with status 1.
 *
 * @param state Global state.
 * @return Nothing (exits).
 */
void	error_exit(t_state *state)
{
	write(2, "Error\n", 6);
	state_free(state);
	exit(1);
}
