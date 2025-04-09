/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:33:24 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/09 18:31:52 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define W_HEIGHT 540
#define W_WIDTH 960
#define MLX_ERROR "%serror :\e[0m mlx pointer is null\n"
#define WINDOW_ERROR "%serror :\e[0m window pointer is null\n"

int	free_mlx(void *mlx, void *window, char *err_msg)
{
	ft_fprintf(2, err_msg, RED);
	if (window)
		mlx_destroy_window(mlx, window);
	if (mlx)
	{
		mlx_destroy_display(mlx);
    	free(mlx);
	}
	return (0);
}

int	mlx_setup_img(void **mlx, void **window, t_imgd *img)
{
	*mlx = mlx_init();
	if (!*mlx)
		return (ft_fprintf(2, MLX_ERROR, RED), 0);
	*window = mlx_new_window(*mlx, W_WIDTH, W_HEIGHT, "fdf");
	if (!*window)
		return (free_mlx(*mlx, *window, WINDOW_ERROR), 0);
	img->img = mlx_new_image(*mlx, W_WIDTH ,W_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
		&img->endian);
}
