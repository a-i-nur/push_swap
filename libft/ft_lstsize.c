/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:54:39 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:39:20 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Count the number of nodes in a list.
 *
 * Traverses the linked list starting at @p lst and returns the number
 * of nodes encountered until a NULL pointer is reached.
 *
 * @param lst Pointer to the first node of the list.
 * @return int Number of nodes in the list.
 */
int	ft_lstsize(t_list *lst)
{
	int		count_lst;

	count_lst = 0;
	while (lst)
	{
		count_lst++;
		lst = lst->next;
	}
	return (count_lst);
}

/*int main(void)
{
    t_list *a = ft_lstnew("A");
    t_list *b = ft_lstnew("B");
    t_list *c = ft_lstnew("C");

    ft_lstadd_front(&a, b); // b -> a
    ft_lstadd_front(&b, c); // c -> b -> a

    int size = ft_lstsize(c);
    printf("List size: %d\n", size); // Выведет: 3
}*/