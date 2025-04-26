/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_rotation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:49:04 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/26 01:44:27 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	rotate_top_right(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->rotation.x += 0.1f;
	rotate_projection(mlx, map, cam, rdr);
	return (1);
}

int	rotate_bot_left(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->rotation.x -= 0.1f;
	rotate_projection(mlx, map, cam, rdr);
	return (1);
}

int	rotate_bot_right(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->rotation.y += 0.1f;
	rotate_projection(mlx, map, cam, rdr);
	return (1);
}

int	rotate_top_left(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	cam->rotation.y -= 0.1f;
	rotate_projection(mlx, map, cam, rdr);
	return (1);
}
