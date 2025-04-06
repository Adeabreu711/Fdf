/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:29:05 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/07 13:26:39 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Erase the first "n" bytes of the memory area pointed to.
 * @param {void*} "s" pointer to the targeted memory location.
 * @param {size_t} "n" size.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
