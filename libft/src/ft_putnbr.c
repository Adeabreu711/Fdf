/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:07:40 by alex              #+#    #+#             */
/*   Updated: 2025/01/06 18:10:01 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert the given int "n" in a string and write it
 * in the standart entry.
 * @return The amount of writed characters.
 */
int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count = (write(1, "-", 1));
		n = -n;
	}
	c = (n % 10) + 48;
	if (n > 9)
		count += ft_putnbr(n / 10);
	return (count + write(1, &c, 1));
}
