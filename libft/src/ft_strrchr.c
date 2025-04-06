/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:09:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/07 13:25:45 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
/**
 * @return A pointer targeting the last char (int "c")
 * encountered in the given string "s".
 */
char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*temp;

	i = -1;
	temp = NULL;
	while (s[++i])
		if ((unsigned char)s[i] == (unsigned char)c)
			temp = (unsigned char *)(s + i);
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return ((char *)temp);
}
