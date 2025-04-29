/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:19:18 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 19:31:30 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void draw_text(t_mlxinfo *mlx, char *str, t_ivec3 info)
{
	info.x *= mlx->w_sf;
	info.y *= mlx->w_sf;
	mlx_string_put(mlx->mlx, mlx->window, info.x, info.y, info.z, str);
}

void	draw_fdf_txt(t_fdf *fdf, char *str)
{
	static char	*fd_nm;

	if (!fd_nm && str)
		fd_nm = str;
	if (!fd_nm)
		return ;
	draw_text(&fdf->mlx, fd_nm, ft_nivec3(215, 74, 0xFFFFFF));
	draw_text(&fdf->mlx, "INFO", ft_nivec3(764, 103, 0x000000));
	draw_text(&fdf->mlx, "Isometric", ft_nivec3(760, 130, 0xFFFFFF));
	draw_text(&fdf->mlx, "Vertices  : ", ft_nivec3(760, 160, 0xFFFFFF));
	draw_text(&fdf->mlx, "Edges     : ", ft_nivec3(760, 180, 0xFFFFFF));
	draw_text(&fdf->mlx, "Faces     : ", ft_nivec3(760, 200, 0xFFFFFF));
	draw_text(&fdf->mlx, "Triangles : ", ft_nivec3(760, 220, 0xFFFFFF));
	draw_text(&fdf->mlx, "Zoom  : [100%]", ft_nivec3(760, 260, 0xFFFFFF));
	draw_text(&fdf->mlx, "Color :", ft_nivec3(760, 280, 0xFFFFFF));
}
