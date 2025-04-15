/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:02:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/15 19:14:03 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	debug_points(t_point3 *points)
{
	int	i;

	i = -1;
	while (points[++i].v3.x)
	{
		ft_printf("(%i,%i,%i,%i)\n",points[i].v3.x,
			points[i].v3.y, points[i].v3.z, points[i].color);
	}
}
