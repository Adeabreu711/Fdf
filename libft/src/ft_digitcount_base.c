/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:18:36 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/13 14:49:57 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @return The number of digits in the give int "dec" (decimal)
 * converted into the given base "base_to" .
 */
int	ft_digitcount_base(int dec, char *base_to)
{
	int	count;
	int	temp;
	int	base_len;

	if (!dec)
		return (0);
	base_len = ft_strlen(base_to);
	temp = 1;
	count = 0;
	while (temp <= dec)
	{
		temp *= base_len;
		count++;
	}
	return (count);
}
