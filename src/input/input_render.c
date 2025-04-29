/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:13:03 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 13:54:27 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

static void	reset_ctrls(t_cam *cam, t_map *map, t_rdr *rdr)
{
	t_ivec2	min_max[4];

	set_min_max_xy(map, min_max, rdr->prj[cam->ctrl.prj_id]);
	cam->ctrl.rotation = ft_nfvec3(0, 0, 0);
	cam->ctrl.scale = get_scale(cam, min_max);
	cam->ctrl.offset = get_center_offset(cam, min_max);
}

int	swap_projection(t_fdf *fdf, int id)
{
	fdf->cam.ctrl.prj_id = id;
	reset_ctrls(&fdf->cam, &fdf->map, &fdf->rdr);
	reset_rotation(&fdf->map, &fdf->cam);
	refresh_projection(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr);
	return (1);
}

int	key_render(int keycode, t_fdf *fdf)
{
	if (keycode == XK_F1)
		return (swap_projection(fdf, 0));
	else if (keycode == XK_F2)
		return (swap_projection(fdf, 1));
	else if (keycode == XK_F3)
		return (swap_projection(fdf, 2));
	return (0);
}
