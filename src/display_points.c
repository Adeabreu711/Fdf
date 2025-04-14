/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:18:46 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/14 20:10:55 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
			printf("draw at : (%i,%i,%i) to (%i,%i,%i)\n", map.pts[i].x, map.pts[i].y, map.pts[i].z, map.pts[i+1].x, map.pts[i+1].y, map.pts[i+1].z);
			draw_line(img, map.pts[i], map.pts[i+1]);
		}
	}
	return (1);
}
