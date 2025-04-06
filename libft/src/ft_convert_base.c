/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:54:16 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/11 23:49:18 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

/**
 * @brief Add to the given char * "s" the result of the
 * decimal to base convertion.
 */
static void	ft_strnbr_to_base(int n, char *base, char *s)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		ft_memset(s, '-', 1);
		n = -n;
	}
	if (n > base_len - 1)
	{
		ft_strnbr_to_base(n / base_len, base, s);
		ft_strnbr_to_base(n % base_len, base, s);
	}
	else
		ft_memmove(s + ft_strlen(s), base + n, 1);
}

/**
 * @brief Converts the given string "n" into another base.
 *
 * @param n Pointer to the string representing the value to convert.
 * @param base_from Pointer to the string representing the
 * base of the input value "n".
 * @param base_to Pointer to the string representing the desired target base.
 * @return A pointer to the converted string "n" in the given
 * target base "base_to".
 */
char	*ft_convert_base(char *n, char *base_from, char *base_to)
{
	char	*s;
	int		dec;

	dec = ft_atoi_base(n, base_from);
	s = ft_calloc(ft_digitcount_base(dec, base_to) + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_strnbr_to_base(dec, base_to, s);
	return (s);
}
