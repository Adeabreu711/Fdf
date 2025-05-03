/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:06:35 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 19:31:52 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Frees memory and resources held by the mlxinfo struct
int	free_mlx(t_mlxinfo *mlx)
{
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

// Calculates the scale factor based on window dimensions
float	get_window_sf(void)
{
	t_fvec2	scale_f;

	scale_f.x = (float)(W_WIDTH / 960);
	scale_f.y = (float)(W_HEIGHT / 540);
	if (scale_f.x < scale_f.y)
		return (scale_f.x);
	return (scale_f.y);
}

// Destroys and recreates the image, reinitializing it with new settings
void	refresh_img(t_mlxinfo *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->w_dim.x, mlx->w_dim.y);
	img_init(&mlx->img);
}
