/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:02:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/16 19:51:52 by alex             ###   ########.fr       */
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
		ft_printf("point[%i] : (%i,%i,%i), color : %i\n", i, map.pts[i].v3.x,
			map.pts[i].v3.y, map.pts[i].v3.z, map.pts[i].color);
	}
}

void	debug_cam(t_cam cam, int map_size, int show_pts)
{
	int	i;

	i = -1;
	ft_printf("\n___CAMERA___ \n");
	printf("offset : (%i,%i)\nscale : %f\n\n", cam.offset.x, cam.offset.y, cam.scale);
	while (++i < map_size && show_pts)
	{
		ft_printf("point[%i] : (%i,%i), color : %i\n", i, cam.pts[i].v2.x,
			cam.pts[i].v2.y, cam.pts[i].color);
	}
}

void	debug_center(t_mlxinfo mlx)
{
	t_point2 p0 = {W_WIDTH / 2, 0, 0xFF0000};
	t_point2 p1 = {W_WIDTH / 2, W_HEIGHT, 0xFF0000};
	t_point2 p2 = {0, W_HEIGHT / 2, 0xFF0000};
	t_point2 p3 = {W_WIDTH, W_HEIGHT / 2, 0xFF0000};
	draw_line(&mlx.img, p0, p1);
	draw_line(&mlx.img, p2, p3);
}
