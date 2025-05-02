/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:19:18 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 02:33:00 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_text(t_mlxinfo *mlx, char *str, t_ivec3 info)
{
	info.x *= mlx->w_sf;
	info.y *= mlx->w_sf;
	mlx_string_put(mlx->mlx, mlx->window, info.x, info.y, info.z, str);
}

void	draw_ui_ctrl(t_fdf *fdf, int color)
{
	draw_text(&fdf->mlx, "Move : [WASD]", ft_nivec3(20, 527, color));
	draw_text(&fdf->mlx, "Rotate : X[O/K] Y[I/L] Z[<-/->]",
		ft_nivec3(120, 527, color));
	draw_text(&fdf->mlx, "Zoom : [mouse_wheel]", ft_nivec3(330, 527, color));
	draw_text(&fdf->mlx, "Projection : [F1 F2 F3]", ft_nivec3(465, 527, color));
	draw_text(&fdf->mlx, "Height : [+/-]", ft_nivec3(625, 527, color));
	draw_text(&fdf->mlx, "Color : [up/down]", ft_nivec3(730, 527, color));
	draw_text(&fdf->mlx, "show tris : [T]", ft_nivec3(850, 527, color));
}

void	draw_ui_txt(t_fdf *fdf)
{
	if (fdf->ui.fd_nm)
		draw_text(&fdf->mlx, fdf->ui.fd_nm, ft_nivec3(215, 74, 0xFFFFFF));
	draw_text(&fdf->mlx, "INFO", ft_nivec3(764, 103, 0x000000));
	if (fdf->ui.prj_nm)
		draw_text(&fdf->mlx, fdf->ui.prj_nm, ft_nivec3(760, 130, 0xFFFFFF));
	if (fdf->ui.vrtcs)
		draw_text(&fdf->mlx, fdf->ui.vrtcs, ft_nivec3(760, 160, 0xFFFFFF));
	if (fdf->ui.edgs)
		draw_text(&fdf->mlx, fdf->ui.edgs, ft_nivec3(760, 180, 0xFFFFFF));
	if (fdf->ui.fcs)
		draw_text(&fdf->mlx, fdf->ui.fcs, ft_nivec3(760, 200, 0xFFFFFF));
	if (fdf->ui.tris)
		draw_text(&fdf->mlx, fdf->ui.tris, ft_nivec3(760, 220, 0xFFFFFF));
	if (fdf->ui.zoom)
		draw_text(&fdf->mlx, fdf->ui.zoom, ft_nivec3(760, 260, 0xFFFFFF));
	draw_text(&fdf->mlx, "Color", ft_nivec3(760, 280, 0xFFFFFF));
	draw_ui_ctrl(fdf, 0xBBBBBB);
	if (!fdf->cam.ctrl.color_id)
		draw_text(&fdf->mlx, "[Default]", ft_nivec3(796, 280, 0xFFFFFF));
	else
		draw_text(&fdf->mlx, "[       ]", ft_nivec3(796, 280, 0xFFFFFF));
}
