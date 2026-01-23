/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:32:33 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:42:22 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Apply a function to the content of each list node.
 *
 * Iterates through the list @p lst, applying @p f to the content of each node.
 * If @p lst or @p f is NULL, no action is taken.
 *
 * @param lst Pointer to the first node of the list.
 * @param f Function to apply to each node's content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

/* void	print_content(void *content)
{
	printf("%s\n", (char *)content);
} */

/* int	main(void)
{
	t_list *a = ft_lstnew("Hello");
	t_list *b = ft_lstnew("42");
	t_list *c = ft_lstnew("Network");

	a->next = b;
	b->next = c;

	ft_lstiter(a, print_content);
    print_content(a->content);
	// Вывод:
	// Hello
	// 42
	// Network

	return (0);
} */