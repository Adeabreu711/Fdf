/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:47:53 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/15 20:42:37 by alex             ###   ########.fr       */
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

void	scale_map(t_map *map, float scale)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (++i < map->size)
		scale_point(&map->pts[i], scale);
}

// void	get_scale(t_map *map)
// {
// 	int	i;

// 	if (!map)
// 		return ;
// 	i = -1;
// }

t_ivec2	get_center_offset(t_map map, t_ivec2 w_dim)
{
	t_ivec2	offset;
	int		col_len;

	col_len = map.size / map.row_len;
	offset.x = w_dim.x / map.row_len;
	offset.y = w_dim.y / col_len;
	printf("dim.x : %i, dim.y : %i\n", w_dim.x, w_dim.y);
	printf("mp_len : %i, rw_len : %i, cl_len : %i\n", map.size, map.row_len, col_len);
	return (offset);
}
