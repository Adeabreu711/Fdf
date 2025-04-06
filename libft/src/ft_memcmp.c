/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:16:01 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/17 16:16:03 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * @brief Compare the two pointers "s1" and "s2" given until "n" char.
 * @param {constvoid*} "s1" pointer to the first compared memory area.
 * @param {constvoid*} "s2" pointer to the memory area to compare.
 * @param {size_t} "n" size.
 * @return The first difference encountered between "s1" and "s2" (s1 - s2).
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (--n > 0 && *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		i++;
	return ((int)(*(unsigned char *)(s1 + i)) - (*(unsigned char *)(s2 + i)));
}
