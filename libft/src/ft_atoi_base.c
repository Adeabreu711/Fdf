/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:04:31 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/11 23:59:36 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	base_contain(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' '
			|| base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

/**
 * @return A int corresponding to the given string.
 * @exception
 * The string can start with whitespaces, signs "-+" and numbers.
 * the base cannot have identical chars and the following chars " +-"
 */
int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	long	result;
	int		digit;
	int		base_len;

	i = 0;
	sign = 1;
	result = 0;
	base_len = ft_strlen(base);
	if (!check_base(base))
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign = -sign;
	digit = base_contain(str[i], base);
	while (str[i++] && digit >= 0)
	{
		result = result * base_len + digit;
		digit = base_contain(str[i], base);
	}
	return ((int)(result * sign));
}
