/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:24:13 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/17 15:24:14 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * @brief Compare the two strings "s1" and "s2" until "n" char.
 * @param {constchar*} "s1" pointer to the first compared string.
 * @param {constchar*} "s2" pointer to the string to compare.
 * @param {size_t} "n" size.
 * @return The first char difference encountered between "s1" and "s2" (s1 - s2).
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (n-- > 1 && (unsigned char)s1[i] && (unsigned char)s2[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
