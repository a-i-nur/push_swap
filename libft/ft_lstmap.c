/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:08:44 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:42:46 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstadd_tail(t_list **head, t_list **tail, t_list *new_node)
{
	if (!*head)
	{
		*head = new_node;
		*tail = new_node;
	}
	else
	{
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * @brief Create a new list by applying a function to each node's content.
 *
 * Traverses @p lst and applies @p f to each node's content. Allocates a new
 * node for each result and links them into a new list. If allocation fails
 * at any point, the @p del function is used to free the content of the
 * created nodes and the function returns NULL.
 *
 * @param lst Pointer to the first node of the original list.
 * @param f Function applied to each node's content to produce new content.
 * @param del Function to free content if allocation fails.
 * @return t_list* Pointer to the new list, or NULL on failure.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_newlst;
	t_list	*tail_newlst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	head_newlst = NULL;
	tail_newlst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&head_newlst, del);
			return (NULL);
		}
		ft_lstadd_tail(&head_newlst, &tail_newlst, new_node);
		lst = lst->next;
	}
	return (head_newlst);
}

/*void	*str_to_upper(void *content)
{
	char	*str = (char *)content;
	char	*new = strdup(str);  // копируем строку
	for (int i = 0; new[i]; i++)
		if (new[i] >= 'a' && new[i] <= 'z')
			new[i] -= 32;
	return (new);
}

void	del_content(void *content)
{
	free(content);
}

void	print_content(void *content)
{
	puts((char *)content);
}

 int	main(void)
 {
 	t_list *a = ft_lstnew(strdup("hello"));
 	t_list *b = ft_lstnew(strdup("world"));
 	a->next = b;

 	t_list *upper = ft_lstmap(a, str_to_upper, del_content);

 	// Выведет:
 	// HELLO
 	// WORLD
     ft_lstiter(upper, print_content);

 	// Чистим память
 	ft_lstclear(&a, del_content);
 	ft_lstclear(&upper, del_content);
 	return (0);
 }*/