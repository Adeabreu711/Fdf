/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:47:53 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/14 19:55:03 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	scale_point(t_point *pt, float scale)
{
	if (!pt)
		return ;
	pt->x *= scale;
	pt->y *= scale;
	pt->z *= scale;
}

void	scale_map(t_map *map, float scale)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (++i < map->size)
		scale_point(&map->pts[i], scale);
}
