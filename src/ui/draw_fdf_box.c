/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:19:39 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/03 15:13:46 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Set box corners with scale and offset applied to dimensions
static void	set_crns(t_mlxinfo *mlx, t_ivec2 dim, t_ivec2 off, t_ivec2 crns[2])
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

// Draw color boxes based on current selected color gradient
static void	draw_ui_color(t_fdf *fdf, t_ivec2 crns[2])
{
	set_crns(&fdf->mlx, ft_nivec2(8, 8), ft_nivec2(329, 5), crns);
	draw_frect(&fdf->mlx, crns, fdf->rdr.c_grad[fdf->cam.ctrl.color_id - 1].x);
	set_crns(&fdf->mlx, ft_nivec2(8, 8), ft_nivec2(342, 5), crns);
	draw_frect(&fdf->mlx, crns, fdf->rdr.c_grad[fdf->cam.ctrl.color_id - 1].y);
	set_crns(&fdf->mlx, ft_nivec2(8, 8), ft_nivec2(355, 5), crns);
	draw_frect(&fdf->mlx, crns, fdf->rdr.c_grad[fdf->cam.ctrl.color_id - 1].z);
}

// Draw main UI display layout including borders and elements
static void	draw_ui_display(t_fdf *fdf, t_ivec2 crns[2])
{
	set_crns(&fdf->mlx, ft_nivec2(540, 360), ft_nivec2(0, 0), crns);
	draw_rect(&fdf->mlx, crns, 1, 0XFFFFFF);
	set_crns(&fdf->mlx, ft_nivec2(90, 21), ft_nivec2(-225, -200), crns);
	draw_rect(&fdf->mlx, crns, 1, 0XFFFFFF);
	set_crns(&fdf->mlx, ft_nivec2(30, 15), ft_nivec2(295, -172), crns);
	draw_frect(&fdf->mlx, crns, 0XFFFFFF);
	set_crns(&fdf->mlx, ft_nivec2(962, 35), ft_nivec2(0, 252), crns);
	draw_rect(&fdf->mlx, crns, 1, 0XFFFFFF);
}

// Draw the full UI box including color if any color is enabled
void	draw_ui_box(t_fdf *fdf)
{
	t_ivec2	crns[2];

	draw_ui_display(fdf, crns);
	if (fdf->cam.ctrl.color_id)
		draw_ui_color(fdf, crns);
}
