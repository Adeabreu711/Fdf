/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:38:50 by alex              #+#    #+#             */
/*   Updated: 2025/04/29 01:35:48 by alde-abr         ###   ########.fr       */
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
static t_point2	*get_projection(t_map mp, t_cam cm, t_ivec2(*f)(t_ctrl, t_fvec3))
{
	t_point2	*pts;
	int			i;

	i = -1;
	pts = ft_calloc(mp.size + 1, sizeof(t_point2));
	if (!pts)
		return (NULL);
	while (++i < mp.size)
	{
		pts[i].v2 = f(cm.ctrl, cm.v_rota[i]);
		pts[i].color = mp.pts[i].color;
	}
	return (pts);
}

//return the scale needed to show the map at 60% of the size of the window.
static float	get_scale(t_cam cam, t_ivec2 *min_max)
{
	t_fvec2	scale;
	int		dsp_width;
	int		dsp_height;

	dsp_width = cam.stgs.dsp[1].x - cam.stgs.dsp[0].x;
	dsp_height = cam.stgs.dsp[1].y - cam.stgs.dsp[0].y;
	scale.x = (float)dsp_width / (float)(min_max[1].x + 1 - min_max[0].x);
	scale.y = (float)dsp_height / (float)(min_max[3].y + 1 - min_max[2].y);
	if (scale.x < scale.y)
		return (scale.x * 0.8f);
	return (scale.y * 0.8f);
}

//return a ivec2 with the offset needed to place the map in the center.
t_ivec2	get_center_offset(t_cam cam, t_ivec2 *min_max)
{
	t_ivec2	prj_ctr;
	t_ivec2	dsp_ctr;
	t_ivec2	offset;

	prj_ctr.x = ((min_max[0].x + min_max[1].x) * cam.ctrl.scale / 2);
	prj_ctr.y = ((min_max[2].y + min_max[3].y) * cam.ctrl.scale / 2);
	dsp_ctr.x = (cam.stgs.dsp[0].x + cam.stgs.dsp[1].x) / 2;
	dsp_ctr.y = (cam.stgs.dsp[0].y + cam.stgs.dsp[1].y) / 2;
	offset.x = dsp_ctr.x - prj_ctr.x;
	offset.y = dsp_ctr.y - prj_ctr.y;
	return (offset);
}

//return a camera with the settings adapted to the given projection.
t_cam	init_cam(t_map map, t_ivec2 w_dim, t_ivec2 size, t_rdr rdr)
{
	t_cam	cam;
	t_ivec2	min_max[4];
	t_ivec2	dsp[2];

	assign_display(w_dim, size, dsp);
	cam = new_cam(NULL, dsp[0], dsp[1]);
	set_min_max_xy(map, min_max, rdr.prj[0]);
	cam.ctrl.scale = get_scale(cam, min_max);
	cam.ctrl.offset = get_center_offset(cam, min_max);
	cam.v_rota = get_rotation(map, 0, 0);
	cam.pts = get_projection(map, cam, rdr.prj[0]);
	return (cam);
}
