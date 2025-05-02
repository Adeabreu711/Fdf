/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:19:39 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 02:00:52 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_box_crns(t_mlxinfo *mlx, t_ivec2 dim, t_ivec2 off, t_ivec2 crns[2])
{
	dim.x *= mlx->w_sf;
	dim.y *= mlx->w_sf;
	off.x *= mlx->w_sf;
	off.y *= mlx->w_sf;
	crns[0] = ft_nivec2((mlx->w_dim.x - dim.x) / 2 + off.x,
			(mlx->w_dim.y - dim.y) / 2 + off.y);
	crns[1] = ft_nivec2((mlx->w_dim.x + dim.x) / 2 + off.x,
			(mlx->w_dim.y + dim.y) / 2 + off.y);
}

void	draw_ui_color(t_fdf *fdf, t_ivec2 crns[2], t_ivec2 dsp[2])
{
	set_box_crns(&fdf->mlx, ft_nivec2(8, 8), ft_nivec2(329, 5), crns);
	draw_frect(&fdf->mlx.img, crns, dsp,
		fdf->rdr.c_grad[fdf->cam.ctrl.color_id - 1].x);
	set_box_crns(&fdf->mlx, ft_nivec2(8, 8), ft_nivec2(342, 5), crns);
	draw_frect(&fdf->mlx.img, crns, dsp,
		fdf->rdr.c_grad[fdf->cam.ctrl.color_id - 1].y);
	set_box_crns(&fdf->mlx, ft_nivec2(8, 8), ft_nivec2(355, 5), crns);
	draw_frect(&fdf->mlx.img, crns, dsp,
		fdf->rdr.c_grad[fdf->cam.ctrl.color_id - 1].z);
}

void	draw_ui_display(t_fdf *fdf, t_ivec2 crns[2], t_ivec2 dsp[2])
{
	set_box_crns(&fdf->mlx, ft_nivec2(540, 360), ft_nivec2(0, 0), crns);
	draw_rect(&fdf->mlx.img, crns, 1, dsp);
	set_box_crns(&fdf->mlx, ft_nivec2(90, 21), ft_nivec2(-225, -200), crns);
	draw_rect(&fdf->mlx.img, crns, 1, dsp);
	set_box_crns(&fdf->mlx, ft_nivec2(30, 15), ft_nivec2(295, -172), crns);
	draw_frect(&fdf->mlx.img, crns, dsp, 0XFFFFFF);
	set_box_crns(&fdf->mlx, ft_nivec2(962, 35), ft_nivec2(0, 252), crns);
	draw_rect(&fdf->mlx.img, crns, 1, dsp);
}

void	draw_ui_box(t_fdf *fdf)
{
	t_ivec2	dsp[2];
	t_ivec2	crns[2];

	dsp[0] = ft_nivec2(-1, 0);
	dsp[1] = ft_nivec2(fdf->mlx.w_dim.x, fdf->mlx.w_dim.y);
	draw_ui_display(fdf, crns, dsp);
	if (fdf->cam.ctrl.color_id)
		draw_ui_color(fdf, crns, dsp);
}
