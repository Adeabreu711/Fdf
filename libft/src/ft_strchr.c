/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:46:42 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/13 19:46:44 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * @return The pointer at the first "c" int encountered in the given string "s",
 * NULL if "c" not found.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
