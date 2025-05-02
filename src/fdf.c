/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:25:08 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 02:33:00 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx-linux/mlx.h"
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
		return (ft_printf("error\n"), free_mlx(&fdf.mlx));
	center_map_pivot(&fdf.map);
	init_projections(&fdf.rdr);
	init_gradients(&fdf.rdr);
	fdf.cam = init_cam(&fdf.map, fdf.mlx.w_dim, ft_nivec2(540, 360), &fdf.rdr);
	fdf.ui = init_ui(&fdf.cam, &fdf.map, &fdf.rdr, argv[1]);
	draw_ui_box(&fdf);
	display_points(&fdf.mlx.img, &fdf.cam, &fdf.map);
	put_img_to_window(&fdf.mlx, 0, 0);
	draw_ui_txt(&fdf);
	receive_inputs(&fdf);
	mlx_loop(fdf.mlx.mlx);
	return (close_window(&fdf));
}
