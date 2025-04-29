/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:05:31 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 13:01:17 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	translate_left(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	if (cam->ctrl.offset.x <= cam->stgs.lmt_offset_x.x)
		return (1);
	cam->ctrl.offset.x -= 5;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	translate_right(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	if (cam->ctrl.offset.x >= cam->stgs.lmt_offset_x.y)
		return (1);
	cam->ctrl.offset.x += 5;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	translate_up(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	if (cam->ctrl.offset.y <= cam->stgs.lmt_offset_y.x)
		return (1);
	cam->ctrl.offset.y -= 5;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	translate_down(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	if (cam->ctrl.offset.y >= cam->stgs.lmt_offset_y.y)
		return (1);
	cam->ctrl.offset.y += 5;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	key_offset(int keycode, t_fdf *fdf)
{
	if (keycode == XK_a)
		return (translate_left(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	else if (keycode == XK_d)
		return (translate_right(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	else if (keycode == XK_w)
		return (translate_up(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	else if (keycode == XK_s)
		return (translate_down(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	return (0);
}
