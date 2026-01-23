/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:30:59 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/10 13:21:04 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocate zero-initialized storage for an array.
 *
 * Allocates memory for an array of @p count_obj elements of @p size_per_obj
 * bytes each and returns a pointer to the allocated memory. The memory is
 * set to zero bytes. If the allocation fails, returns NULL.
 *
 * @param count_obj Number of elements.
 * @param size_per_obj Size of each element in bytes.
 * @return void* Pointer to zeroed memory, or NULL on failure.
 */
void	*ft_calloc(size_t count_obj, size_t size_per_obj)
{
	void	*result;
	size_t	total_size;

	if (count_obj == 0 || size_per_obj == 0)
		return (malloc(0));
	if (count_obj > SIZE_MAX / size_per_obj)
		return (NULL);
	total_size = count_obj * size_per_obj;
	result = malloc(total_size);
	if (!result)
		return (NULL);
	ft_bzero(result, total_size);
	return (result);
}
