/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:07:03 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/10 12:25:18 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Delete and free an entire list.
 *
 * Iterates through the list pointed to by @p lst, deletes each node by calling
 * @p del on its content and freeing the node. Sets *@p lst to NULL.
 * If @p lst is NULL, no action is taken.
 *
 * @param lst Address of the pointer to the first node of the list.
 * @param del Function used to free each node's content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}

/* void	del_content(void *content)
{
	free(content);
} */

/*int	main(void)
{
	t_list *a = ft_lstnew(malloc(5));
	t_list *b = ft_lstnew(malloc(10));
	t_list *c = ft_lstnew(malloc(15));

	a->next = b;
	b->next = c;

	ft_lstclear(&a, del_content);
	// теперь a, b, c и их content — полностью освобождены
	// a == NULL
	return (0);
}*/