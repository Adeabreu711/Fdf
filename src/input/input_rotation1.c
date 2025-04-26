/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_rotation1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:50:53 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/26 01:44:30 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	rotate_projection(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	refresh_img(mlx);
	reset_rotation(map, cam);
	apply_rotation(map, cam, 'y', cam->rotation.y);
	apply_rotation(map, cam, 'x', cam->rotation.x);
	apply_rotation(map, cam, 'z', cam->rotation.z);
	apply_projection(map, cam, rdr.prj[cam->prj_id]);
	display_points(&mlx->img, *cam, map);
	put_img_to_window(mlx, 0, 0);
	return (1);
}

int	rotate_left(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->rotation.z += 0.1f;
	rotate_projection(mlx, map, cam, rdr);
	return (1);
}

int	rotate_right(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->rotation.z -= 0.1f;
	rotate_projection(mlx, map, cam, rdr);
	return (1);
}

int	key_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Left)
		rotate_left(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	else if (keycode == XK_Right)
		rotate_right(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	else if (keycode == XK_o)
		rotate_top_left(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	else if (keycode == XK_p)
		rotate_top_right(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	else if (keycode == XK_m)
		rotate_bot_right(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	else if (keycode == XK_l)
		rotate_bot_left(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	return (0);
}
