/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:18:46 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 01:31:26 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_diagonal(int i, t_imgd *img, t_cam *cam, t_map *map)
{
	if ((i + 1) % map->row_len != 0 && i + map->row_len < map->size)
		draw_line(img, cam->pts[i],
			cam->pts[i + map->row_len + 1], cam->stgs.dsp);
}

//display the camera points at the screen.
int	display_points(t_imgd *img, t_cam *cam, t_map *map)
{
	int	i;

	if (!cam->pts || !img)
		return (0);
	i = -1;
	while (++i < map->size)
	{
		if (i + map->row_len < map->size)
			draw_line(img, cam->pts[i],
				cam->pts[i + map->row_len], cam->stgs.dsp);
		if ((i + 1) % map->row_len != 0 && i + 1 < map->size)
			draw_line(img, cam->pts[i], cam->pts[i + 1], cam->stgs.dsp);
		if (cam->ctrl.show_tri)
			draw_diagonal(i, img, cam, map);
	}
	return (1);
}
