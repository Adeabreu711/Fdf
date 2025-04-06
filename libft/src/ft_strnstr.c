/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:09:21 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/17 17:09:22 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Search a targeted string "little" in a string "big".
 * @param {constchar*} "big" pointer to a string.
 * @param {constchar*} "little" pointer to the string to find.
 * @param {size_t} "len" size.
 * @return A pointer to the first string "little" encountered in "big".
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	little_len;

	little_len = ft_strlen(little);
	if (!little_len)
		return ((char *)big);
	i = 0;
	while (big[i] && (len - i >= little_len))
	{
		j = 0;
		while (little[j])
		{
			if ((unsigned char)big[i + j] != (unsigned char)little[j])
				break ;
			j++;
		}
		if (j == little_len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
