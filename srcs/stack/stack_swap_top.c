/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:47:41 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:47:42 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap the first two nodes of a stack (in place).
 *
 * Iterates only through a few pointers to relink nodes.
 *
 * @param stack Stack to modify.
 * @return Nothing.
 */
void	stack_swap_top(t_stack *stack)
{
	t_node	*old_top;
	t_node	*new_top;
	t_node	*third;

	if (!stack || stack->size < 2)
		return ;
	old_top = stack->top;
	new_top = old_top->next;
	old_top->next = new_top->next;
	old_top->prev = new_top;
	new_top->next = old_top;
	new_top->prev = NULL;
	stack->top = new_top;
	third = old_top->next;
	if (stack->size == 2)
	{
		old_top->next = NULL;
		stack->bottom = old_top;
	}
	else if (stack->size > 2)
	{
		third->prev = old_top;
	}
}
