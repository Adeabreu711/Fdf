/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:33:26 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/18 20:33:27 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Write the given char "c" in the given folder "fd".
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
