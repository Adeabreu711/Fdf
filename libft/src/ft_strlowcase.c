/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:28:51 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/19 21:48:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief convert all the uppercase chars in the given string
 * "str" to lowercase exept the charset "expt".
 */
char	*ft_strlowcase(char *str, char *expt)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90 && !ft_strchr(expt, str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
