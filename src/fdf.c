/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:25:08 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/14 20:03:31 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

#define SCALE 10

int	main(int argc, char *argv[])
{
	t_mlxinfo	mlx;
	t_map	map;

	if (argc != 2 || !mlx_setup_img(&mlx))
		return (1);
	if (!parse_map(open(argv[1], O_RDONLY), &map))
		return (ft_printf("error"), 1);
	scale_map(&map, SCALE);
	// debug_points(points);
	// printf("point 1 : %i,%i,%i\n", map.pts[28].x, map.pts[28].y, map.pts[28].z);
	display_points(&mlx.img, map);
	put_img_to_window(&mlx, 0, 0);
	mlx_loop(mlx.mlx);
	return (free(map.pts) ,free_mlx(&mlx, ""));
}

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
