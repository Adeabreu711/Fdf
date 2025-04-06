/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:07:32 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/29 18:03:45 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Print the given bits (char size).
 */
void	ft_putbits(char bits)
{
	int				i;
	unsigned char	mask;

	i = -1;
	mask = 0b10000000;
	while (++i < (int)(sizeof(unsigned char) * 8))
	{
		ft_putchar((!!(mask & bits)) + '0');
		mask >>= 1;
	}
}
