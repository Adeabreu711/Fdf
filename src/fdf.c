/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:25:08 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/27 16:11:19 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"
#include <math.h>

void	center_map_pivot(t_map *map)
{
	int		i;
	t_fvec3	pivot;

	pivot.x = (float)(map->row_len / 2);
	pivot.y = (float)((map->size / map->row_len) / 2);
	pivot.z = 0;
	i = -1;
	while (++i < map->size)
	{
		map->pts[i].v3.x -= pivot.x;
		map->pts[i].v3.y -= pivot.y;
		map->pts[i].v3.z -= pivot.z;
	}
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2 || !mlx_setup_img(&fdf.mlx))
		return (1);
	if (!parse_map(open(argv[1], O_RDONLY), &fdf.map))
		return (ft_printf("error\n"), 1);
	center_map_pivot(&fdf.map);
	init_projections(&fdf.rdr);
	fdf.cam = init_cam(fdf.map, fdf.mlx.w_dim, fdf.rdr);
	//
	debug_map(fdf.map, 0);
	debug_cam(fdf.cam, fdf.map, 0);
	//
	display_points(&fdf.mlx.img, fdf.cam, fdf.map);
	put_img_to_window(&fdf.mlx, 0, 0);
	mlx_hook(fdf.mlx.window, 17, 0, close_window, &fdf);
	mlx_hook(fdf.mlx.window, 2, 1L << 0, key_hook, &fdf);
	mlx_hook(fdf.mlx.window, 4, 1L << 2, mouse_hook, &fdf);
	mlx_loop(fdf.mlx.mlx);
	return (close_window(&fdf));
}
