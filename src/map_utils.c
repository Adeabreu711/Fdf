/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:47:53 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/16 21:37:57 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	scale_point(t_point3 *pt, float scale)
{
	if (!pt)
		return ;
	pt->v3.x *= scale;
	pt->v3.y *= scale;
	pt->v3.z *= scale;
}

void	scale_cam(t_map *map, float scale)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (++i < map->size)
		scale_point(&map->pts[i], scale);
}

t_ivec2	get_center_offset(t_map map, t_ivec2 w_dim, float scale)
{
	t_ivec2	offset;
	int		col_len;

	col_len = map.size / map.row_len;
	offset.x = (int)((w_dim.x / 2) - (((map.row_len - 1) * scale) / 2));
	offset.y = (int)((w_dim.y / 2) - (((col_len - 1) * scale) / 2));
	printf("dim.x : %i, dim.y : %i\n", w_dim.x, w_dim.y);
	return (offset);
}
