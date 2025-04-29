/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:33:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/28 22:48:36 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	zoom_in(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	cam->ctrl.scale += 0.2f;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}

int	zoom_out(t_mlxinfo *mlx, t_map *map, t_cam *cam, t_rdr *rdr)
{
	cam->ctrl.scale -= 0.2f;
	refresh_projection(mlx, map, cam, rdr);
	return (1);
}
