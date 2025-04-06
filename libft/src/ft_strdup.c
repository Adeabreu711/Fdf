/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:42:36 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/13 17:04:36 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @return A pointer directing to a copy of the given string "s".
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	int		s_len;

	s_len = ft_strlen(s);
	dup = malloc((s_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[s_len] = '\0';
	while (s_len-- > 0)
		dup[s_len] = s[s_len];
	return (dup);
}
