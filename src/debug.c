/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:02:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/25 15:47:58 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	debug_map(t_map map, int show_pts)
{
	int	i;

	i = -1;
	ft_printf("\n___MAP___ \n");
	ft_printf("raw_len : %i\nmap_size : %i\n", map.row_len, map.size);
	ft_printf("W_WIDTH : %i\nM_HEIGHT : %i\n\n", W_WIDTH, W_HEIGHT);
	while (++i < map.size && show_pts)
	{
		ft_printf("point[%i] : (%i,%i,%i), color : %x\n", i, map.pts[i].v3.x,
			map.pts[i].v3.y, map.pts[i].v3.z, map.pts[i].color);
	}
}

void	debug_cam(t_cam cam, t_map map, int show_pts)
{
	int	i;

	i = -1;
	ft_printf("\n___CAMERA___ \n");
	printf("offset : (%i,%i)\nscale : %f\n", cam.offset.x, cam.offset.y, cam.scale);
	while (++i < map.size && show_pts)
	{
		ft_printf("point[%i] : (%i,%i), color : %x\n", i, cam.pts[i].v2.x,
			cam.pts[i].v2.y, cam.pts[i].color);
	}
	i = -1;
	while (++i < map.size && show_pts)
	{
		printf("rota[%i] : (%f,%f,%f)\n", i, cam.v_rota[i].x,
			cam.v_rota[i].y, cam.v_rota[i].z);
	}
	printf("0(%i,%i), 1(%i, %i), 2(%i, %i), 3(%i,%i)\n\n", cam.pts[0].v2.x,
			cam.pts[0].v2.y, cam.pts[map.row_len - 1].v2.x, cam.pts[map.row_len -1].v2.y,
			cam.pts[map.size - map.row_len].v2.x, cam.pts[map.size - map.row_len].v2.y,
			cam.pts[map.size - 1].v2.x, cam.pts[map.size - 1].v2.y);
}

// void	debug_center(t_mlxinfo mlx)
// {
// 	t_point2 p0 = {W_WIDTH / 2, 0, 0xFF0000};
// 	t_point2 p1 = {W_WIDTH / 2, W_HEIGHT, 0xFF0000};
// 	t_point2 p2 = {0, W_HEIGHT / 2, 0xFF0000};
// 	t_point2 p3 = {W_WIDTH, W_HEIGHT / 2, 0xFF0000};
// 	draw_line(&mlx.img, p0, p1);
// 	draw_line(&mlx.img, p2, p3);
// }
