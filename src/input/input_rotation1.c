/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_rotation1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:50:53 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/30 13:12:41 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	rotate_projection(t_fdf *fdf)
{
	refresh_img(&fdf->mlx);
	reset_rotation(&fdf->map, &fdf->cam);
	apply_rotation(&fdf->map, &fdf->cam, 'y', fdf->cam.ctrl.rotation.y);
	apply_rotation(&fdf->map, &fdf->cam, 'x', fdf->cam.ctrl.rotation.x);
	apply_rotation(&fdf->map, &fdf->cam, 'z', fdf->cam.ctrl.rotation.z);
	apply_projection(&fdf->map, &fdf->cam, fdf->rdr.prj[fdf->cam.ctrl.prj_id]);
	draw_fdf_box(&fdf->mlx);
	display_points(&fdf->mlx.img, &fdf->cam, &fdf->map);
	put_img_to_window(&fdf->mlx, 0, 0);
	draw_fdf_txt(fdf);
	return (1);
}

int	rotate_left(t_fdf *fdf)
{
	fdf->cam.ctrl.rotation.z += 0.1f;
	rotate_projection(fdf);
	return (1);
}

int	rotate_right(t_fdf *fdf)
{
	fdf->cam.ctrl.rotation.z -= 0.1f;
	rotate_projection(fdf);
	return (1);
}

int	key_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Left)
		return (rotate_left(fdf));
	else if (keycode == XK_Right)
		return (rotate_right(fdf));
	else if (keycode == XK_o)
		return (rotate_top_left(fdf));
	else if (keycode == XK_p)
		return (rotate_top_right(fdf));
	else if (keycode == XK_m)
		return (rotate_bot_right(fdf));
	else if (keycode == XK_l)
		return (rotate_bot_left(fdf));
	return (0);
}
