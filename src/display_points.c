/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:18:46 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/21 22:17:15 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//display the camera points at the screen.
int	display_points(t_imgd *img, t_cam cam, t_map map)
{
	int	i;

	if (!cam.pts || !img)
		return (0);
	i = -1;
	while (++i < map.size)
	{
		if (i + map.row_len < map.size)
			draw_line(img, cam.pts[i], cam.pts[i + map.row_len]);
		if ((i + 1) % map.row_len != 0 && i + 1 < map.size)
			draw_line(img, cam.pts[i], cam.pts[i + 1]);
	}
	return (1);
}
