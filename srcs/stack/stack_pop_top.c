/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:47:56 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:47:57 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Remove and return the top node of a stack.
 *
 * If the stack is empty, returns NULL.
 *
 * @param stack Stack to modify.
 * @return Detached top node, or NULL.
 */
t_node	*stack_pop_top(t_stack *stack)
{
	t_node	*back_node;
	t_node	*new_top;

	if (!stack || stack->size == 0)
		return (NULL);
	back_node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
		stack->size = 0;
	}
	else if (stack->size > 1)
	{
		new_top = back_node->next;
		stack->top = new_top;
		new_top->prev = NULL;
		stack->size--;
	}
	back_node->next = NULL;
	back_node->prev = NULL;
	return (back_node);
}
