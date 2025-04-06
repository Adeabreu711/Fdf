/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:31:59 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/13 19:32:02 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy up to size - 1 of string of the "src" to the "dest" area.
 * @param {void*} "dest" pointer to the destination string (to replace).
 * @param {void*} "src" pointer to the source string (to copy).
 * @param {size_t} "size" size.
 * @return The src lenght - 1 ("src").
 * @deprecated Use ft_memmove instead.
 */
size_t	ft_strlcpy(char *dst, char *src, size_t siz)
{
	int	i;

	i = -1;
	if (!siz)
		return (ft_strlen(src));
	while (src[++i] && (unsigned int)i < siz - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
