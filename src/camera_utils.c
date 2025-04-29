/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:47:00 by alex              #+#    #+#             */
/*   Updated: 2025/04/29 13:44:02 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//create a new cam with the given params.
t_cam	new_cam(t_point2 *pts, t_ivec2 tl_crn, t_ivec2 br_crn)
{
	t_cam	cam;

	cam.pts = pts;
	cam.v_rota = NULL;
	cam.ctrl.offset = ft_nivec2(0, 0);
	cam.ctrl.rotation = ft_nfvec3(0.0f, 0.0f, 0.0f);
	cam.ctrl.show_tri = 0;
	cam.ctrl.color_id = 0;
	cam.ctrl.prj_id = 0;
	cam.ctrl.height = 2.0f;
	cam.ctrl.scale = 1;
	cam.stgs.dsp[0] = tl_crn;
	cam.stgs.dsp[1] = br_crn;
	return (cam);
}

//free the given cam and reset settings.
void	free_cam(t_cam *cam)
{
	if (cam->pts)
		free(cam->pts);
	if (cam->v_rota)
		free(cam->v_rota);
	cam->ctrl.offset = ft_nivec2(0, 0);
	cam->stgs.dsp[0] = ft_nivec2(0, 0);
	cam->stgs.dsp[1] = ft_nivec2(0, 0);
	cam->ctrl.scale = 0;
	cam->ctrl.color_id = 0;
	cam->ctrl.height = 0;
	cam->ctrl.prj_id = 0;
}

// return the the minimum and maximum values of the map.
// [0]min_x, [1]max_x
// [2]min_y, [3]max_y
void	set_min_max_xy(t_map *map, t_ivec2 mm[4], t_ivec2(*f)(t_ctrl, t_fvec3))
{
	int		i;
	t_ivec2	pt;

	i = -1;
	while (++i < 4)
		mm[i] = ft_nivec2(0, 0);
	i = -1;
	while (++i < map->size)
	{
		pt = f(new_cam(NULL, ft_nivec2(0, 0), ft_nivec2(0, 0)).ctrl,
				ft_nfvec3(map->pts[i].v3.x, map->pts[i].v3.y, map->pts[i].v3.z));
		if (pt.x < mm[0].x)
			mm[0] = pt;
		if (pt.x > mm[1].x)
			mm[1] = pt;
		if (pt.y < mm[2].y)
			mm[2] = pt;
		if (pt.y > mm[3].y)
			mm[3] = pt;
	}
}

t_ivec2	get_min_max_z(t_map *map)
{
	t_ivec2	min_max;
	int		i;

	i = -1;
	min_max = ft_nivec2(0, 0);
	while (++i < map->size)
	{
		if (min_max.x > map->pts[i].v3.z)
			min_max.x = map->pts[i].v3.z;
		if (min_max.y < map->pts[i].v3.z)
			min_max.y = map->pts[i].v3.z;
	}
	return (min_max);
}
