/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:47:20 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/11 18:47:21 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Copy "n" bytes of the "src" memory area pointed to the "dest" area .
 * @param {void*} "dest" pointer to the destination memory location (to replace).
 * @param {void*} "src" pointer to the source memory location (to copy).
 * @param {size_t} "n" size.
 * @return The destination memory location ("dest").
 * @exception /!\ Pointers must not overlap (use ft_memmove instead).
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	i = -1;
	while (++i < n)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (dest - i);
}
