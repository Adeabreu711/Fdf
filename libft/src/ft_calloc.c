/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:24:33 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/07 13:23:11 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @return A pointer with "elementCount" elements with a "size" size,
 * all values are init to '\0'.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*mem;
	unsigned int	c_size;
	int				i;

	i = -1;
	c_size = nmemb * size;
	if (c_size < nmemb && c_size < size)
		return (NULL);
	mem = malloc(c_size);
	if (!mem)
		return (NULL);
	while (++i < (int)c_size)
		*(unsigned char *)(mem + i) = 0;
	return (mem);
}
