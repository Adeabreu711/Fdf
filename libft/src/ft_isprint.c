/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:46:48 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/11 15:46:50 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @return True if the given value is an ASCII printable char, false if not.
 * @exception SPACE(32) included.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
