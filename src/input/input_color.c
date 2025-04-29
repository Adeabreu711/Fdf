/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:26:25 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/28 23:25:05 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

void	apply_color(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	if (cam->ctrl.color_id == 0)
		get_dflt_color(map, cam);
	else
		color_map(map, cam, rdr->c_grad[cam->ctrl.color_id - 1]);
	refresh_projection(mlx, map, cam, rdr);
}

int	next_color(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	cam->ctrl.color_id++;
	if (cam->ctrl.color_id > COLOR_S)
		cam->ctrl.color_id = 0;
	apply_color(mlx, map, cam, rdr);
	return (1);
}

int	previous_color(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	cam->ctrl.color_id--;
	if (cam->ctrl.color_id < 0)
		cam->ctrl.color_id = COLOR_S;
	apply_color(mlx, map, cam, rdr);
	return (1);
}

int	key_color(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Up)
		return (next_color(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	else if (keycode == XK_Down)
		return (previous_color(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	return (0);
}
