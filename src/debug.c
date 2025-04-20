/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:02:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/20 03:16:58 by alex             ###   ########.fr       */
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

void	debug_cam(t_cam cam, t_map map, int show_pts)
{
	int	i;

	i = -1;
	ft_printf("\n___CAMERA___ \n");
	printf("offset : (%i,%i)\nscale : %f\n", cam.offset.x, cam.offset.y, cam.scale);
	while (++i < map.size && show_pts)
	{
		ft_printf("point[%i] : (%i,%i), color : %i\n", i, cam.pts[i].v2.x,
			cam.pts[i].v2.y, cam.pts[i].color);
	}
	printf("0(%i,%i), 1(%i, %i), 2(%i, %i), 3(%i,%i)\n\n", cam.pts[0].v2.x, 
			cam.pts[0].v2.y, cam.pts[map.row_len - 1].v2.x, cam.pts[map.row_len -1].v2.y,
			cam.pts[map.size - map.row_len].v2.x, cam.pts[map.size - map.row_len].v2.y,
			cam.pts[map.size - 1].v2.x, cam.pts[map.size - 1].v2.y);
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
void	debug_prj_center(t_mlxinfo mlx, t_map map, t_cam cam, t_ivec2(*f)(t_cam, t_ivec3))
{
	// int	i;
	// t_ivec2		*crns; 
	// t_ivec2		center;
	// t_ivec2		offset;

	// i = -1;
	// crns = get_corners(map, cam, f);
	// offset.x = 354;
	// offset.y = 200;
	// center.x = (((crns[1].x + crns[3].x) / 2) + offset.x);
	// center.y = (((crns[0].y + crns[2].y) / 2) + offset.y);
	// t_point2 p0 = {0, center.y, 0x0000FF};
	// t_point2 p1 = {W_WIDTH, center.y, 0x0000FF};
	// t_point2 p2 = {center.x, 0, 0x0000FF};
	// t_point2 p3 = {center.x, W_HEIGHT, 0x0000FF};

	// printf("p0 : (%i,%i), p1 : (%i,%i), p2 : (%i, %i), p3 : (%i,%i)\n", p0.v2.x, p0.v2.y, p1.v2.x, p1.v2.y, p2.v2.x, p2.v2.y, p3.v2.x, p3.v2.y);
	// draw_line(&mlx.img, p0, p1);
	// draw_line(&mlx.img, p2, p3);
	// free (crns);
}
void	debug_corners(t_mlxinfo mlx, t_cam cam, t_map map)
{
	t_point2 p0 = {cam.pts[0].v2.x, cam.pts[0].v2.y, 0xFF0000}; //RED
	t_point2 p1 = {cam.pts[map.row_len - 1].v2.x, cam.pts[map.row_len - 1].v2.y, 0x0000FF}; //BLUE
	t_point2 p2 = {cam.pts[map.size - map.row_len].v2.x, cam.pts[map.size - map.row_len].v2.y, 0x00FF00}; //GREEN
	t_point2 p3 = {cam.pts[map.size - 1].v2.x, cam.pts[map.size - 1].v2.y, 0xFFFF00}; //YELLOW

	put_pixel(&mlx.img, p0.v2.x, p0.v2.y, p0.color);
	put_pixel(&mlx.img, p1.v2.x, p1.v2.y, p1.color);
	put_pixel(&mlx.img, p2.v2.x, p2.v2.y, p2.color);
	put_pixel(&mlx.img, p3.v2.x, p3.v2.y, p3.color);
}
