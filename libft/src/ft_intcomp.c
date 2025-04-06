/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcomp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:06:48 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/12 00:00:34 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @return The greatest or lowest gived int depending of "upper".
 */
int	ft_intcomp(int i, int j, t_uint16 upper)
{
	int	sign;

	sign = 1;
	if (!upper)
		sign = -1;
	if (i * sign > j * sign)
		return (i);
	return (j);
}
