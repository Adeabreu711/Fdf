/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:47:00 by alex              #+#    #+#             */
/*   Updated: 2025/04/28 17:01:02 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//create a new cam with the given params.
t_cam	new_cam(t_point2 *pts, t_ivec2 dsp)
{
	t_cam	cam;

	cam.pts = pts;
	cam.v_rota = NULL;
	cam.offset = ft_nivec2(0, 0);
	cam.rotation = ft_nfvec3(0.0f, 0.0f, 0.0f);
	cam.show_tri = 0;
	cam.color_id = 0;
	cam.prj_id = 0;
	cam.height = 2.0f;
	cam.scale = 1;
	cam.stgs.dsp = dsp;
	return (cam);
}

//free the given cam and reset settings.
void	free_cam(t_cam *cam)
{
	if (cam->pts)
		free(cam->pts);
	if (cam->v_rota)
		free(cam->v_rota);
	cam->offset = ft_nivec2(0, 0);
	cam->stgs.dsp = ft_nivec2(0, 0);
	cam->scale = 0;
}

//return the the minimum and maximum values of the map.
//[0]min_x, [1]max_x
//[2]min_y, [3]max_y
t_ivec2	*get_min_max_xy(t_map map, t_ivec2(*f)(t_cam, t_fvec3))
{
	int		i;
	t_ivec2	*min_max;
	t_ivec2	pt;

	i = -1;
	min_max = ft_calloc(5, sizeof(t_ivec2));
	if (!min_max)
		return (min_max);
	while (++i < 3)
		min_max[i] = ft_ivec2_op(min_max[i], ft_nivec2(0, 0), ft_mult);
	i = -1;
	while (++i < map.size)
	{
		pt = f(new_cam(NULL, ft_nivec2(0, 0)),
			ft_nfvec3(map.pts[i].v3.x, map.pts[i].v3.y, map.pts[i].v3.z));
		if (pt.x < min_max[0].x)
			min_max[0] = pt;
		if (pt.x > min_max[1].x)
			min_max[1] = pt;
		if (pt.y < min_max[2].y)
			min_max[2] = pt;
		if (pt.y > min_max[3].y)
			min_max[3] = pt;
	}
	return (min_max);
}

t_ivec2 get_min_max_z(t_map map)
{
	t_ivec2	min_max;
	int		i;

	i = -1;
	min_max = ft_nivec2(0, 0);
	while(++i < map.size)
	{
		if (min_max.x > map.pts[i].v3.z)
			min_max.x = map.pts[i].v3.z;
		if (min_max.y < map.pts[i].v3.z)
			min_max.y = map.pts[i].v3.z;
	}
	return (min_max);
}
