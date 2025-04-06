/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:04:31 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/18 13:04:32 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Trim start/end characters in a string.
 * @param {charconst*} "s1" pointer to the string to cut.
 * @param {char} "set" a string containing a set of char to trim in
 * the given string "s1".
 * @return A copy of the string "s1" without the characters given in "set"
 * at the start and the end of the string.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	start = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	start = i;
	while (s1[i])
		i++;
	while (i > 0 && ft_strchr(set, s1[i]))
		i--;
	end = i;
	str = ft_substr(s1, start, end - start + 1);
	if (!str)
		return (NULL);
	return (str);
}
