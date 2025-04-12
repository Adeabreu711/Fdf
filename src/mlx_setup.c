/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:33:24 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/12 20:19:44 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define W_HEIGHT 540
#define W_WIDTH 960
#define MLX_ERROR "%serror :\e[0m mlx pointer is null\n"
#define WINDOW_ERROR "%serror :\e[0m window pointer is null\n"

int	free_mlx(t_mlxinfo *mlx, char *err_msg)
{
	ft_fprintf(2, err_msg, RED);
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx, mlx->img.img);
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	return (0);
}

void	put_img_to_window(t_mlxinfo *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, x, y);
}

void	img_init(t_imgd *img)
{
	img->addr = mlx_get_data_addr(&img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
}

int	mlx_setup_img(t_mlxinfo *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (ft_fprintf(2, MLX_ERROR, RED), 0);
	mlx->window = mlx_new_window(mlx->mlx, W_WIDTH, W_HEIGHT, "fdf");
	if (!mlx->window)
		return (free_mlx(mlx, WINDOW_ERROR), 0);
	mlx->img.img = mlx_new_image(mlx->mlx, W_WIDTH ,W_HEIGHT);
	img_init(&mlx->img);
	return (1);
}
