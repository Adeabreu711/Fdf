/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:25:08 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/03 15:05:31 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/input.h"
#include <math.h>

// Initialize FDF, parse map, set up camera, and handle UI/display.
int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2 || !mlx_setup_img(&fdf.mlx))
		return (1);
	if (!parse_map(open(argv[1], O_RDONLY), &fdf.map))
		return (free_mlx(&fdf.mlx));
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
