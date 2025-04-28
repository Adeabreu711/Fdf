/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:38:50 by alex              #+#    #+#             */
/*   Updated: 2025/04/28 17:05:24 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//return a list of point rotated to the given direction.
static t_fvec3	*get_rotation(t_map map, char axis, float angle)
{
	t_fvec3	*pts;
	int		i;

	i = -1;
	pts = ft_calloc(map.size + 1, sizeof(t_fvec3));
	if (!pts)
		return (NULL);
	while (++i < map.size)
		pts[i] = rotate(ft_nfvec3(map.pts[i].v3.x,
					map.pts[i].v3.y, map.pts[i].v3.z), angle, axis);
	return (pts);
}

//return a list of point projected to the given direction.
static t_point2	*get_projection(t_map mp, t_cam cm, t_ivec2(*f)(t_cam, t_fvec3))
{
	t_point2	*pts;
	int			i;

	i = -1;
	pts = ft_calloc(mp.size + 1, sizeof(t_point2));
	if (!pts)
		return (NULL);
	while (++i < mp.size)
	{
		pts[i].v2 = f(cm, cm.v_rota[i]);
		pts[i].color = mp.pts[i].color;
	}
	return (pts);
}

//return the scale needed to show the map at 60% of the size of the window.
static float	get_scale(t_cam cam, t_ivec2 *min_max)
{
	t_fvec2	scale;

	scale.x = (float)(cam.stgs.dsp.x
			/ (float)(min_max[1].x + 1 - min_max[0].x));
	scale.y = (float)(cam.stgs.dsp.y
			/ (float)(min_max[3].y + 1 - min_max[2].y));
	if (scale.x < scale.y)
		return ((float)scale.x * 0.6f);
	return ((float)scale.y * 0.6f);
}

//return a ivec2 with the offset needed to place the map in the center.
t_ivec2	get_center_offset(t_cam cam, t_ivec2 *min_max)
{
	t_ivec2	prj_ctr;
	t_ivec2	offset;

	prj_ctr.x = ((min_max[0].x + min_max[1].x) * cam.scale / 2);
	prj_ctr.y = ((min_max[2].y + min_max[3].y) * cam.scale / 2);
	offset.x = cam.stgs.dsp.x / 2 - prj_ctr.x;
	offset.y = cam.stgs.dsp.y / 2 - prj_ctr.y;
	return (offset);
}

//return a camera with the settings adapted to the given projection.
t_cam	init_cam(t_map map, t_ivec2 dsp, t_rdr rdr)
{
	t_cam	cam;
	t_ivec2	*min_max;

	cam = new_cam(NULL, dsp);
	min_max = get_min_max_xy(map, rdr.prj[0]);
	cam.scale = get_scale(cam, min_max);
	cam.offset = get_center_offset(cam, min_max);
	cam.v_rota = get_rotation(map, 0, 0);
	cam.pts = get_projection(map, cam, rdr.prj[0]);
	free(min_max);
	return (cam);
}
