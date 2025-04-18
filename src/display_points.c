/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:18:46 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/19 00:22:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	display_points(t_imgd *img, t_cam cam, t_map map)
{
	int	i;

	if (!cam.pts || !img)
		return (0);
	i = -1;
	while (++i < map.size)
	{
		if (i / map.row_len < map.size / map.row_len - 1)
			draw_line(img, cam.pts[i], cam.pts[i + map.row_len]);
		if (i % map.row_len != map.row_len - 1)
		{
			//printf("i : %i,draw at : (%i,%i) to (%i,%i)\n", i, cam.pts[i].v2.x, cam.pts[i].v2.y, cam.pts[i+1].v2.x, cam.pts[i+1].v2.y);
			draw_line(img, cam.pts[i], cam.pts[i+1]);
		}
	}
	return (1);
}
