/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:17:21 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/18 20:17:23 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/**
 * @brief Aplly a function to all char of a given string.
 * @param {charconst*} "s" pointer to a string.
 * @param {void(*f)} (unsignedint,char*) pointer to a fonction that
 * modifie characters one by one.
 * @return the given string with the chars modified by the given function.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = -1;
	while (s[++i])
		f(i, &s[i]);
}
