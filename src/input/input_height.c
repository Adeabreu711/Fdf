/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:32:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 13:17:24 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	reduce_height(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	if (cam->ctrl.height >= cam->stgs.lmt_height.y)
		return (1);
	cam->ctrl.height += 0.2f * cam->ctrl.height;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	add_height(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	if (cam->ctrl.height <= cam->stgs.lmt_height.x)
		return (1);
	cam->ctrl.height -= 0.2f * cam->ctrl.height / 2;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	key_height(int keycode, t_fdf *fdf)
{
	if (keycode == XK_KP_Add)
		return (add_height(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	else if (keycode == XK_KP_Subtract)
		return (reduce_height(&fdf->mlx, &fdf->map, &fdf->cam, &fdf->rdr));
	return (0);
}
