/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:19:18 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/30 20:36:30 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	draw_text(t_mlxinfo *mlx, char *str, t_ivec3 info)
{
	info.x *= mlx->w_sf;
	info.y *= mlx->w_sf;
	mlx_string_put(mlx->mlx, mlx->window, info.x, info.y, info.z, str);
}

void	draw_fdf_txt(t_fdf *fdf)
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
	draw_text(&fdf->mlx, "Color :", ft_nivec3(760, 280, 0xFFFFFF));
}
