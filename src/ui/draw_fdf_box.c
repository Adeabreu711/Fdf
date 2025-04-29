/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:19:39 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 16:23:34 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_ui_fbox(t_mlxinfo *mlx, t_ivec2 dsp[2], t_ivec2 dim, t_ivec2 off)
{
	t_ivec2	crns[2];

	dim.x *= mlx->w_sf;
	dim.y *= mlx->w_sf;
	off.x *= mlx->w_sf;
	off.y *= mlx->w_sf;
	crns[0] = ft_nivec2((mlx->w_dim.x - dim.x) / 2 + off.x,
		(mlx->w_dim.y - dim.y) / 2 + off.y);
	crns[1] = ft_nivec2((mlx->w_dim.x + dim.x) / 2 + off.x,
		(mlx->w_dim.y + dim.y) / 2 + off.y);
	draw_filled_rect(&mlx->img, crns, dsp);
}

void	draw_ui_box(t_mlxinfo *mlx, t_ivec2 dsp[2], t_ivec2 dim, t_ivec2 off)
{
	t_ivec2	crns[2];

	dim.x *= mlx->w_sf;
	dim.y *= mlx->w_sf;
	off.x *= mlx->w_sf;
	off.y *= mlx->w_sf;
	crns[0] = ft_nivec2((mlx->w_dim.x - dim.x) / 2 + off.x,
		(mlx->w_dim.y - dim.y) / 2 + off.y);
	crns[1] = ft_nivec2((mlx->w_dim.x + dim.x) / 2 + off.x,
		(mlx->w_dim.y + dim.y) / 2 + off.y);
	draw_rect(&mlx->img, crns, 1, dsp);
}

void	draw_fdf_box(t_mlxinfo *mlx)
{
	t_ivec2	dsp[2];

	dsp[0] = ft_nivec2(0, 0);
	dsp[1] = ft_nivec2(mlx->w_dim.x, mlx->w_dim.y);
	draw_ui_box(mlx, dsp, ft_nivec2(540, 360), ft_nivec2(0, 0));
	draw_ui_box(mlx, dsp, ft_nivec2(90, 21), ft_nivec2(-225, -200));
	draw_ui_fbox(mlx, dsp, ft_nivec2(30, 15), ft_nivec2(305, -169));
}
