/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:47:00 by alex              #+#    #+#             */
/*   Updated: 2025/04/20 03:50:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//create a new cam with the given params.
t_cam	new_cam(t_point2 *pts, t_ivec2 dsp)
{
	t_cam	cam;

	cam.pts = pts;
	cam.offset = ft_nivec2(0, 0);
	cam.scale = 1;
	cam.dsp = dsp;
	return (cam);
}

//free the given cam and reset settings.
void	free_cam(t_cam *cam)
{
	if (cam->pts)
		free(cam->pts);
	cam->offset = ft_nivec2(0, 0);
	cam->dsp = ft_nivec2(0, 0);
	cam->scale = 0;
}

//return the the minimum and maximum values of the map.
//[0]min_x, [1]max_x
//[2]min_y, [3]max_y
t_ivec2	*get_min_max(t_map map, t_ivec2(*f)(t_cam, t_ivec3))
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
		pt = f(new_cam(NULL, ft_nivec2(0, 0)), map.pts[i].v3);
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
