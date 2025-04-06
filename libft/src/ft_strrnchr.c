/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:09:00 by alde-abr          #+#    #+#             */
/*   Updated: 2024/12/30 16:44:14 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
/**
 * @return A pointer targeting the last char (int "c")
 * encountered in given size "n" of the given string "s".
 */
char	*ft_strrnchr(const char *s, int c, size_t n)
{
	int				i;
	unsigned char	*temp;

	i = -1;
	temp = NULL;
	while (s[++i] && n-- > 0)
		if ((unsigned char)s[i] == (unsigned char)c)
			temp = (unsigned char *)(s + i);
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return ((char *)temp);
}
