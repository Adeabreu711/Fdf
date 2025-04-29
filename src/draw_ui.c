/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:19:39 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 02:35:59 by alde-abr         ###   ########.fr       */
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

void	draw_ui_rect(t_imgd *img, t_ivec2 *w_dim, t_ivec2 dim)
{
	t_ivec2	v2[2];
	t_ivec2	dsp[2];
	float	w_sf;

	w_sf = get_window_sf();
	dsp[0] = ft_nivec2(0, 0);
	dsp[1] = ft_nivec2(w_dim->x, w_dim->y);
	dim = ft_ivec2_op(dim, ft_nivec2(w_sf, w_sf), ft_mult);
	v2[0] = ft_nivec2((w_dim->x - dim.x) / 2, (w_dim->y - dim.y) / 2);
	v2[1] = ft_nivec2((w_dim->x + dim.x) / 2, (w_dim->y + dim.y) / 2);
	draw_rect(img, v2, 1, dsp);
	v2[0] = ft_nivec2((w_dim->x - dim.x) / 2, (w_dim->y - dim.y) / 2 - 31);
	v2[1] = ft_nivec2((w_dim->x + dim.x) / 2 - 475, (w_dim->y + dim.y) / 2 - 370);
	draw_rect(img, v2, 1, dsp);
	// draw_filled_rect(img, v2, dsp);
}

void draw_text(t_mlxinfo *mlx, char *fd_nm)
{
	mlx_string_put(mlx->mlx, mlx->window, 215, 74, 0xFFFFFF, fd_nm);
}
