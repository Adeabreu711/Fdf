/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:50:53 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/26 02:07:55 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

void	reset_rotation(t_map map, t_cam *cam);
void	apply_rotation(t_map map, t_cam *cam, char axis, float angle);
void	apply_projection(t_map mp, t_cam *cm, t_ivec2(*f)(t_cam, t_fvec3));

int	close_window(t_fdf *fdf)
{
	if (fdf && fdf->mlx.mlx)
		mlx_loop_end(fdf->mlx.mlx);
	free(fdf->map.pts);
	free_cam(&fdf->cam);
	free_mlx(&fdf->mlx, "");
	exit(0);
	return (0);
}

int	refresh_projection(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr)
{
	refresh_img(mlx);
	apply_projection(map, cam, rdr.prj[cam->prj_id]);
	display_points(&mlx->img, *cam, map);
	put_img_to_window(mlx, 0, 0);
	return (1);
}

void	reset_rotation(t_map map, t_cam *cam)
{
	int	i;

	i = -1;
	while (++i < map.size)
		cam->v_rota[i] = ft_nfvec3
			(map.pts[i].v3.x, map.pts[i].v3.y, map.pts[i].v3.z);
}

void	apply_rotation(t_map map, t_cam *cam, char axis, float angle)
{
	int	i;

	i = -1;
	while (++i < map.size)
		cam->v_rota[i] = rotate(cam->v_rota[i], angle, axis);
}

void	apply_projection(t_map mp, t_cam *cm, t_ivec2(*f)(t_cam, t_fvec3))
{
	int	i;

	i = -1;
	while (++i < mp.size)
		cm->pts[i].v2 = f(*cm, cm->v_rota[i]);
}
