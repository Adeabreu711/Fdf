/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:02:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/12 19:11:55 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	debug_points(t_point *points)
{
	int	i;

	i = -1;
	while (points[++i].x)
	{
		ft_printf("(%i,%i,%i,%i)\n",points[i].x,
			points[i].y, points[i].z, points[i].color);
	}
}
