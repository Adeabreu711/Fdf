/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:50:53 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 02:36:18 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

void	reset_rotation(t_map *map, t_cam *cam);
void	apply_rotation(t_map *map, t_cam *cam, char axis, float angle);
void	apply_projection(t_map *map, t_cam *cam, t_prj_func);

// Close the window, free allocated resources, and exit the program
int	close_window(t_fdf *fdf)
{
	if (fdf && fdf->mlx.mlx)
		mlx_loop_end(fdf->mlx.mlx);
	free(fdf->map.pts);
	free_cam(&fdf->cam);
	free_mlx(&fdf->mlx);
	free_ui(&fdf->ui);
	exit(0);
	return (0);
}

// Refresh image, update the display, and redraw UI elements
int	refresh_projection(t_fdf *fdf)
{
	refresh_img(&fdf->mlx);
	apply_projection(&fdf->map, &fdf->cam, fdf->rdr.prj[fdf->cam.ctrl.prj_id]);
	display_points(&fdf->mlx.img, &fdf->cam, &fdf->map);
	draw_ui_box(fdf);
	put_img_to_window(&fdf->mlx, 0, 0);
	draw_ui_txt(fdf);
	return (1);
}

// Reset camera points to the original map rotation
void	reset_rotation(t_map *map, t_cam *cam)
{
	int	i;

	i = -1;
	while (++i < map->size)
		cam->v_rota[i] = ft_nfvec3
			(map->pts[i].v3.x, map->pts[i].v3.y, map->pts[i].v3.z);
}

// Apply rotation to camera points around the given axis and angle
void	apply_rotation(t_map *map, t_cam *cam, char axis, float angle)
{
	int	i;

	i = -1;
	while (++i < map->size)
		cam->v_rota[i] = rotate(cam->v_rota[i], angle, axis);
}

// Apply projection to rotated map points and store results in camera points
void	apply_projection(t_map *map, t_cam *cam, t_prj_func f)
{
	int	i;

	i = -1;
	while (++i < map->size)
		cam->pts[i].v2 = f(cam->ctrl, cam->v_rota[i]);
}
