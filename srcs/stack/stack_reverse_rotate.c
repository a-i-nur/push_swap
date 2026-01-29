/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:47:49 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:47:47 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Reverse rotate a stack (bottom becomes top).
 *
 * It relinks bottom to the top and updates pointers.
 *
 * @param stack Stack to modify.
 * @return Nothing.
 */
void	stack_reverse_rotate(t_stack *stack)
{
	t_node	*old_top;
	t_node	*old_bottom;
	t_node	*new_bottom;

	if (!stack || stack->size < 2)
		return ;
	old_bottom = stack->bottom;
	new_bottom = old_bottom->prev;
	old_top = stack->top;
	new_bottom->next = NULL;
	stack->bottom = new_bottom;
	old_bottom->prev = NULL;
	old_bottom->next = old_top;
	old_top->prev = old_bottom;
	stack->top = old_bottom;
}
