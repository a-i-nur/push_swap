/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:47:46 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:47:47 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotate a stack (top becomes bottom).
 *
 * It relinks top to the bottom and updates pointers.
 *
 * @param stack Stack to modify.
 * @return Nothing.
 */
void	stack_rotate(t_stack *stack)
{
	t_node	*old_top;
	t_node	*old_bottom;
	t_node	*new_top;

	if (!stack || stack->size < 2)
		return ;
	old_top = stack->top;
	new_top = old_top->next;
	old_bottom = stack->bottom;
	new_top->prev = NULL;
	stack->top = new_top;
	old_bottom->next = old_top;
	old_top->prev = old_bottom;
	old_top->next = NULL;
	stack->bottom = old_top;
}
