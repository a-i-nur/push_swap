/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:27:37 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:37:44 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Create a new list node.
 *
 * Allocates a new list node with its @p content pointer set to the given 
 * value and its @c next pointer set to NULL. Returns NULL if allocation fails.
 *
 * @param content Pointer to the value to store in the new node.
 * @return t_list* Pointer to the newly created node, or NULL on failure.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
