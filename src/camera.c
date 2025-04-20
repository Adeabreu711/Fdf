/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:38:50 by alex              #+#    #+#             */
/*   Updated: 2025/04/20 03:44:43 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//return a list of point projected to the given direction.
static t_point2	*get_projection(t_map mp, t_cam cm, t_ivec2(*f)(t_cam, t_ivec3))
{
	t_point2	*pts;
	int			i;

	i = -1;
	pts = ft_calloc(mp.size + 1, sizeof(t_point2));
	if (!pts)
		return (NULL);
	while (++i < mp.size)
	{
		pts[i].v2 = f(cm, mp.pts[i].v3);
		pts[i].color = mp.pts->color;
	}
	return (pts);
}

//return the scale needed to show the map at 60% of the size of the window.
static float	get_scale(t_map map, t_cam cam, t_ivec2	*min_max)
{
	t_fvec2	scale;

	scale.x = (float)(cam.dsp.x / (float)(min_max[1].x - min_max[0].x));
	scale.y = (float)(cam.dsp.y / (float)(min_max[3].y - min_max[2].y));
	if (scale.x < scale.y)
		return ((float)scale.x * 0.6f);
	return ((float)scale.y * 0.6f);
}

//return a ivec2 with the offset needed to place the map in the center. 
t_ivec2	get_center_offset(t_map map, t_cam cam, t_ivec2 *min_max)
{
	t_ivec2	prj_ctr;
	t_ivec2	offset;

	prj_ctr.x = ((min_max[0].x + min_max[1].x) * cam.scale / 2);
	prj_ctr.y = ((min_max[2].y + min_max[3].y) * cam.scale / 2);
	offset.x = cam.dsp.x / 2 - prj_ctr.x;
	offset.y = cam.dsp.y / 2 - prj_ctr.y;
	return (offset);
}

//return a camera with the settings adapted to the given projection.
t_cam	init_cam(t_map map, t_ivec2 dsp, t_ivec2(*f)(t_cam, t_ivec3))
{
	t_cam	cam;
	t_ivec2	*min_max;

	cam = new_cam(NULL, dsp);
	min_max = get_min_max(map, f);
	cam.scale = get_scale(map, cam, min_max);
	cam.offset = get_center_offset(map, cam, min_max);
	cam.pts = get_projection(map, cam, f);
	free(min_max);
	return (cam);
}
