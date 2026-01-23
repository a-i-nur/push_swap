/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:06:46 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:40:56 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Return the last node of a list.
 *
 * Traverses the list starting at @p lst until the final node whose
 * @c next pointer is NULL. If @p lst is NULL, returns NULL.
 *
 * @param lst Pointer to the first node of the list.
 * @return t_list* Pointer to the last node, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst-> next;
	}
	return (lst);
}

/*int main(void)
{
    t_list *a = ft_lstnew("A");
    t_list *b = ft_lstnew("B");
    t_list *c = ft_lstnew("C");

    ft_lstadd_front(&a, b); // b -> a
    ft_lstadd_front(&b, c); // c -> b -> a

    t_list *last = ft_lstlast(c);
    printf("Last node: %s\n", (char *)last->content); // Выведет: A
}*/