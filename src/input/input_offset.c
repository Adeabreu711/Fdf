/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:05:31 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/27 16:06:32 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	translate_left(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->offset.x -= 2;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	translate_right(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->offset.x += 2;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	translate_up(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->offset.y -= 2;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	translate_down(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->offset.y += 2;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	key_offset(int keycode, t_fdf *fdf)
{
	if (keycode == XK_a)
		translate_left(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	else if (keycode == XK_d)
		translate_right(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	else if (keycode == XK_w)
		translate_up(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	else if (keycode == XK_s)
		translate_down(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	return (0);
}
