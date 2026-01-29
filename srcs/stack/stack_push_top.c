/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:47:49 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:47:50 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Push a node to the top of a stack.
 *
 * If the stack is empty, the node becomes both top and bottom.
 *
 * @param stack Stack to modify.
 * @param node Node to push.
 * @return Nothing.
 */
void	stack_push_top(t_stack *stack, t_node *node)
{
	t_node	*old_top;

	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
		node->prev = NULL;
		node->next = NULL;
		stack->size = 1;
	}
	else if (stack->size > 0)
	{
		old_top = stack->top;
		node->prev = NULL;
		node->next = old_top;
		old_top->prev = node;
		stack->top = node;
		stack->size++;
	}
}
