/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui64itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:07:48 by alde-abre         #+#    #+#             */
/*   Updated: 2025/02/07 12:06:00 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/**
 * @return The number of digits in the the given unsigned long "nb".
 */
int	ft_ui64digitcount(t_uint64 nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

/**
 * @return A string corresponding to the given unsigned long "n".
 */
char	*ft_ui64itoa(t_uint64 nb)
{
	char	*str;
	int		count;

	count = ft_ui64digitcount(nb);
	str = ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (count-- > 0)
	{
		str[count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
