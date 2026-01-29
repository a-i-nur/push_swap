/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_bottom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:47:52 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:47:54 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Push a node to the bottom of a stack.
 *
 * If the stack is empty, the node becomes both top and bottom.
 *
 * @param stack Stack to modify.
 * @param node Node to push.
 * @return Nothing.
 */
void	stack_push_bottom(t_stack *stack, t_node *node)
{
	t_node	*old_bottom;

	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->bottom = node;
		stack->top = node;
		node->prev = NULL;
		node->next = NULL;
		stack->size = 1;
	}
	else if (stack->size > 0)
	{
		old_bottom = stack->bottom;
		node->prev = old_bottom;
		node->next = NULL;
		old_bottom->next = node;
		stack->bottom = node;
		stack->size++;
	}
}
