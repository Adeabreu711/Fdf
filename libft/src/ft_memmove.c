/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:02:00 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/11 20:02:02 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * @brief Copy "n" bytes of the "src" memory area pointed to the "dest" area
 * , pointers can ovelarp.
 * @param {void*} "dest" pointer to the destination memory location (to replace).
 * @param {void*} "src" pointer to the source memory location (to copy).
 * @param {size_t} "n" size.
 * @return The destination memory location ("dest").
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	if (src < dest && dest < src + n)
		while (n-- > 0)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	else
		while (++i < n)
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	return (dest);
}
