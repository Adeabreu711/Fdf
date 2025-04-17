/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:18:46 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/17 02:22:51 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point2	*get_projection(t_map map, t_cam cam)
{
	t_point2	*pts;
	int			i;

	i = -1;
	pts = ft_calloc(map.size + 1, sizeof(t_point2));
	if (!pts)
		return (NULL);
	while (++i < map.size)
	{
		pts[i].v2 = project_iso(cam, map.pts[i].v3);
		pts[i].color = map.pts->color;
	}
	return (pts);
}

void	apply_cam_stgs(t_cam *cam, int map_size)
{
	int	i;

	i = -1;
	while (++i < map_size)
	{
		// cam->pts[i].v2 = ft_ivec2_op(cam->pts[i].v2, 
		// 	ft_nivec2(cam->scale, cam->scale), ft_mult);

		// printf("pt.x[i] : %i, scale : %f, op : %f\n", cam->pts[i].v2.x, cam->scale, (cam->pts[i].v2.x * cam->scale));
		cam->pts[i].v2.x = (int)(cam->pts[i].v2.x * cam->scale);
		cam->pts[i].v2.y = (int)(cam->pts[i].v2.y * cam->scale);
		cam->pts[i].v2 = ft_ivec2_op(cam->pts[i].v2,
			cam->offset, ft_sum);
	}
}

float	get_scale(t_map map, t_ivec2 w_dim, int percent)
{
	int	m_max;
	int	w_max;

	m_max = map.row_len;
	w_max = w_dim.x;
	if (map.row_len > map.size / map.row_len)
		m_max = map.size / map.row_len;
	if (w_dim.x > w_dim.y)
		w_max = w_dim.x;
	//printf("w_max : %i, m_max : %i, op : %f\n", w_max, m_max, (float)(w_max / m_max) * (float)(percent / 100.0));
	return ((float)((w_max / m_max) * (percent / 100.0)));
}

t_cam	init_cam(t_map map, t_ivec2 w_dim)
{
	t_cam	cam;

	// cam.pts =  get_projection(map, project_iso, cam.scale);
	cam.scale = get_scale(map, w_dim, 50);
	cam.offset = get_center_offset(map, w_dim, cam.scale);
	cam.pts = get_projection(map, cam);
	// cam.scale = 6;
	// cam.offset = ft_nivec2(0, 0);
	// apply_cam_stgs(&cam, map.size);
	return (cam);
}

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
			printf("i : %i,draw at : (%i,%i) to (%i,%i)\n", i, cam.pts[i].v2.x, cam.pts[i].v2.y, cam.pts[i+1].v2.x, cam.pts[i+1].v2.y);
			draw_line(img, cam.pts[i], cam.pts[i+1]);
		}
	}
	return (1);
}
