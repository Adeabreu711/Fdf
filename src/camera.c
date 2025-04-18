/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:38:50 by alex              #+#    #+#             */
/*   Updated: 2025/04/19 00:53:49 by alex             ###   ########.fr       */
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

float	get_scale(t_map map, t_cam cam, t_ivec2(*f)(t_cam, t_ivec3))
{
	t_ivec2 *crns;
	t_fvec2	scale;
	
	crns = get_corners(map, cam, f);
	printf("crn[0] : (%i,%i)\ncrn[1] : (%i,%i)\ncrn[2] : (%i,%i)\ncrn[3] : (%i,%i)\n", crns[0].x, crns[0].y, crns[1].x, crns[1].y, crns[2].x, crns[2].y, crns[3].x, crns[3].y );
	scale.x = (float)(cam.dsp.x / (crns[1].x - crns[3].x));
	scale.y = (float)(cam.dsp.y / (crns[2].y - crns[0].y));
	if (scale.x < scale.y)
		return ((float)scale.x * 0.6f);
	return ((float)scale.y * 0.6f);
}


t_ivec2	get_center_offset(t_map map, t_cam cam, t_ivec2(*f)(t_cam, t_ivec3))
{
	t_ivec2	*min_max;
	t_ivec2	prj_ctr;
	t_ivec2	offset;

	min_max = get_min_max(map, f);

	prj_ctr.x = ((min_max[0].x + min_max[1].x ) * cam.scale / 2);
	prj_ctr.y = ((min_max[2].y + min_max[3].y) * cam.scale / 2);
	offset.x = cam.dsp.x / 2 - prj_ctr.x;
	offset.y = cam.dsp.y / 2 - prj_ctr.y;
	printf("min_x(%i,%i), max_x(%i,%i), min_y(%i,%i), max_y(%i,%i)\n",
		min_max[0].x, min_max[0].y, min_max[1].x, min_max[1].y,
		min_max[2].x, min_max[2].y, min_max[3].x, min_max[3].y);
	printf("calc : offset.x : %i, offset.y : %i\n", offset.x, offset.y);
	return (free(min_max), offset);
}

t_cam	init_cam(t_map map, t_ivec2 dsp, t_ivec2(*f)(t_cam, t_ivec3))
{
	t_cam	cam;

	cam = new_cam(NULL, dsp);
	// get_min_max(map, cam, f);
	cam.scale = get_scale(map, cam, f);
	cam.offset = get_center_offset(map, cam, f);
	cam.pts = get_projection(map, cam);
	// printf("pts : %p\n",map.pts);
	return (cam);
}
