/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:24:58 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/19 21:48:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief convert all the lowercase chars in the given string
 * "str" to uppercase exept the charset "expt".
 */
char	*ft_strupcase(char *str, char *expt)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122 && !ft_strchr(expt, str[i]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
