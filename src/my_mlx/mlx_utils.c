/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:06:35 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 13:12:10 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	get_window_sf(void)
{
	t_fvec2	scale_f;

	scale_f.x = (float)(W_WIDTH / 960);
	scale_f.y = (float)(W_HEIGHT / 540);
	if (scale_f.x < scale_f.y)
		return (scale_f.x);
	return (scale_f.y);
}

//destroy image and recreate it with init settings.
void	refresh_img(t_mlxinfo *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->w_dim.x, mlx->w_dim.y);
	img_init(&mlx->img);
}

int	is_in_screen(t_ivec2 v2, t_ivec2 dsp[2])
{
	if (v2.x > dsp[0].x && v2.x < dsp[1].x
		&& v2.y > dsp[0].y && v2.y < dsp[1].y)
		return (1);
	return (0);
}

//put a pixel int the given image at the given coordonate.
void	put_pixel(t_imgd *img, t_ivec2 v2, int color, t_ivec2 dsp[2])
{
	char	*dst;

	if (!is_in_screen(v2, dsp))
		return ;
	dst = img->addr
		+ (v2.y * img->line_length + v2.x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
