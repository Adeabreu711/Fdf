/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:18:46 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/15 20:50:07 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		init_cam(t_map map, t_ivec2 w_dim, t_cam cam)
{
	cam.offset = get_center_offset(map, w_dim);
	printf("off.x : %i, off.y : %i\n", cam.offset.x, cam.offset.y);
}

int	display_points(t_imgd *img, t_map map)
{
	int	i;

	if (!map.pts || !img)
		return (0);
	i = -1;
	while (++i < map.size)
	{
		if (i / map.row_len < map.size / map.row_len)
			draw_line(img, map.pts[i], map.pts[i % map.row_len]);
		if (i % map.row_len != map.row_len - 1)
		{
			printf("draw at : (%i,%i,%i) to (%i,%i,%i)\n", map.pts[i].v3.x, map.pts[i].v3.y, map.pts[i].v3.y, map.pts[i+1].v3.x, map.pts[i+1].v3.y, map.pts[i+1].v3.z);
			draw_line(img, map.pts[i], map.pts[i+1]);
		}
	}
	return (1);
}
