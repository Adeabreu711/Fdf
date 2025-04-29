/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_rotation1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:50:53 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/28 23:27:40 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	rotate_projection(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	refresh_img(mlx);
	reset_rotation(map, cam);
	apply_rotation(map, cam, 'y', cam->ctrl.rotation.y);
	apply_rotation(map, cam, 'x', cam->ctrl.rotation.x);
	apply_rotation(map, cam, 'z', cam->ctrl.rotation.z);
	apply_projection(map, cam, rdr->prj[cam->ctrl.prj_id]);
	draw_ui_rect(&mlx->img, &mlx->w_dim, ft_nivec2(540, 360));
	display_points(&mlx->img, cam, map);
	put_img_to_window(mlx, 0, 0);
	return (1);
}

int	rotate_left(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	cam->ctrl.rotation.z += 0.1f;
	rotate_projection(mlx, map, cam, rdr);
	return (1);
}

int	rotate_right(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	cam->ctrl.rotation.z -= 0.1f;
	rotate_projection(mlx, map, cam, rdr);
	return (1);
}

int	key_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Left)
		return (rotate_left(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	else if (keycode == XK_Right)
		return (rotate_right(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	else if (keycode == XK_o)
		return (rotate_top_left(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	else if (keycode == XK_p)
		return (rotate_top_right(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	else if (keycode == XK_m)
		return (rotate_bot_right(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	else if (keycode == XK_l)
		return (rotate_bot_left(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	return (0);
}
