/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:25:08 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/21 23:43:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

int	close_window(t_fdf *fdf)
{
	mlx_loop_end(fdf->mlx.mlx);
	free(fdf->map.pts);
	free_cam(&fdf->cam);
	free_mlx(&fdf->mlx, "");
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		close_window(fdf);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf		fdf;

	if (argc != 2 || !mlx_setup_img(&fdf.mlx))
		return (1);
	if (!parse_map(open(argv[1], O_RDONLY), &fdf.map))
		return (ft_printf("error\n"), 1);
	fdf.cam = init_cam(fdf.map, fdf.mlx.w_dim, project_iso);
	//
	debug_map(fdf.map, 0);
	debug_cam(fdf.cam, fdf.map, 0);
	//
	display_points(&fdf.mlx.img, fdf.cam, fdf.map);
	put_img_to_window(&fdf.mlx, 0, 0);
	mlx_hook(fdf.mlx.window, 17, 0, close_window, &fdf);
	mlx_key_hook(fdf.mlx.window, key_hook, &fdf);    
	mlx_loop(fdf.mlx.mlx);
	return (close_window(&fdf));
}

// t_point2 p0 = {220, 220, 0xFFFFFF};
// t_point2 p1 = {220, 20, 0xFFFFFF};

// draw_line(&mlx.img, p0, p1);

// t_point p0 = {220, 220, 0, 0xFFFFFF};
// t_point p1 = {220, 20, 0, 0xFFFFFF};

// draw_line(&mlx.img, p0, p1);

	// int res = 32;
	// for (int k = 0; k < res; k++) {
	// 	int offx = 220;
	// 	int offy = 220;
	// 	int rad = 200;
	// 	float angle = (float)k / (float)res * 6.28f;
	// 	float angle2 = (float)((k + 1) % res) / (float)res * 6.28f;
	// 	t_point p0 = {offx, offy};
	// 	t_point p1 = {offx + rad * cos(angle), offy + rad * sin(angle)};
	// 	t_point p2 = {offx + rad * cos(angle2), offy + rad * sin(angle2)};
	// 	draw_line(&img, p0, p1);
	// 	draw_line(&img, p1, p2);
	// }

	// t_point p0 = {220, 220, 0, 0xFFFFFF};
	// t_point p1 = {220, 20, 0, 0xFFFFFF};
	// // t_point p2 = {100, 400, 0, 0xFFFFFF};
	// draw_line(&img, p0, p1);
	// // // draw_line(&img, p2, p1);
