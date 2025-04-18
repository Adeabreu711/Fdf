/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:33:24 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/18 21:46:20 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	mlx_setup_img(t_mlxinfo *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (ft_fprintf(2, MLX_ERROR, RED), 0);
	mlx->w_dim.x = W_WIDTH;
	mlx->w_dim.y = W_HEIGHT;
	mlx->window = mlx_new_window(mlx->mlx, mlx->w_dim.x, mlx->w_dim.y, "fdf");
	if (!mlx->window)
		return (free_mlx(mlx, WINDOW_ERROR), 0);
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->w_dim.x, mlx->w_dim.y);
	if (!mlx->img.img)
		return (free_mlx(mlx, WINDOW_ERROR), 0);
	img_init(&mlx->img);
	if (!mlx->img.addr)
		return (free_mlx(mlx, WINDOW_ERROR), 0);
	return (1);
}
