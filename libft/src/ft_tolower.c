/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:45:43 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/13 19:45:45 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @return The given value in lowercase if it's an uppercase alpha,
 * else return the same value.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
