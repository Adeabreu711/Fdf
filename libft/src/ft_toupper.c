/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:35:25 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/13 19:51:56 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @return The given value in uppercase if it's an lowercase alpha,
 * else return the same value.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
