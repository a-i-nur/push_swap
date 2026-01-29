/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:48:04 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:05 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Create an empty stack with a given name.
 *
 * @param name Stack name, usually 'a' or 'b'.
 * @return Initialized stack struct.
 */
t_stack	stack_new(char name)
{
	t_stack	new_stack;

	new_stack.name = name;
	new_stack.size = 0;
	new_stack.top = NULL;
	new_stack.bottom = NULL;
	return (new_stack);
}
