/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:32:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/28 13:34:19 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	reduce_height(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->height += 0.1f;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	add_height(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->height -= 0.1f;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	key_height(int keycode, t_fdf *fdf)
{
	if (keycode == XK_KP_Add)
		add_height(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	else if (keycode == XK_KP_Subtract)
		reduce_height(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	return (1);
}
