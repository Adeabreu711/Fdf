/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:33:24 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 19:31:50 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define ERR_MLX "%serror :\e[0m mlx pointer is null\n"

// Displays the image in the window at the given coordinates
void	put_img_to_window(t_mlxinfo *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, x, y);
}

// Initializes image data fields for direct pixel access
void	img_init(t_imgd *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

// Sets up the mlx window and image; returns 1 on success, 0 on error
int	mlx_setup_img(t_mlxinfo *mlx)
{
	mlx->mlx = NULL;
	mlx->window = NULL;
	mlx->img.addr = NULL;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (ft_fprintf(2, ERR_MLX, RED), 0);
	mlx->w_dim.x = W_WIDTH;
	mlx->w_dim.y = W_HEIGHT;
	mlx->w_sf = get_window_sf();
	mlx->window = mlx_new_window(mlx->mlx, mlx->w_dim.x, mlx->w_dim.y, "fdf");
	if (!mlx->window)
		return (free_mlx(mlx), 0);
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->w_dim.x, mlx->w_dim.y);
	if (!mlx->img.img)
		return (free_mlx(mlx), 0);
	img_init(&mlx->img);
	if (!mlx->img.addr)
		return (free_mlx(mlx), 0);
	return (1);
}
