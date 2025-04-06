/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:20:21 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/18 12:20:22 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenate two given strings.
 * @return A pointer to a new string resulted to the concatenation of
 * the string "s1" to the string "s2".
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	int				i;
	unsigned int	s1_len;
	unsigned int	s2_len;

	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[s1_len + i] = s2[i];
	return (str);
}
