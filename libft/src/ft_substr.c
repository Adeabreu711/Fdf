/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:57:43 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/18 11:57:44 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @param {charconst*} "s" a pointer to a string.
 * @param {unisgnedstart} "start" the start of the area to copy.
 * @param {size_t} "len" the size of the returned string.
 * @return A pointer directing to a copy of the given string "s"
 * in the given area.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || start >= 4294967295)
	{
		len = 0;
		start = 0;
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[len] = '\0';
	while (len-- > 0)
		dup[len] = s[(start) + len];
	return (dup);
}
