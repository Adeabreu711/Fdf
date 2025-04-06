/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:33:06 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/13 19:33:09 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenate the string "src" to the string "dest", the size must
 *  be the lenght of the final string.
 * @param {void*} "dest" pointer to the destination string (to replace).
 * @param {void*} "src" pointer to the source string (to copy).
 * @param {size_t} "size" size of the desired final string.
 * @return The original src  + dest lenght ('\0' characters not counted).
 * @deprecated Use ft_memmove instead.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int				i;
	unsigned int	dest_length;

	if (size <= (unsigned int)ft_strlen(dest))
		return (size + ft_strlen(src));
	dest_length = ft_strlen(dest);
	i = -1;
	while (src[++i] && dest_length + 1 < size)
		dest[dest_length++] = (unsigned char)src[i];
	dest[dest_length] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
