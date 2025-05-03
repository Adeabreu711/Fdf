/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:37:35 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 19:40:22 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Creates a t_point2 from a position and color
static t_point2	npt2(t_ivec2 v2, int color)
{
	t_point2	pt;

	pt.v2 = v2;
	pt.color = color;
	return (pt);
}

// Draws a rectangle outline with given width and color between two corners
void	draw_rect(t_mlxinfo *mlx, t_ivec2 crns[2], int width, int color)
{
	t_ivec2	dsp[2];
	t_ivec2	tr;
	t_ivec2	bl;
	int		i;

	i = -1;
	dsp[0] = ft_nivec2(-1, 0);
	dsp[1] = ft_nivec2(mlx->w_dim.x, mlx->w_dim.y);
	tr = ft_nivec2(crns[1].x, crns[0].y);
	bl = ft_nivec2(crns[0].x, crns[1].y);
	while (++i < width)
	{
		draw_line(&mlx->img, npt2(ft_nivec2(crns[0].x - i, crns[0].y - i),
				color), npt2(ft_nivec2(tr.x + i, tr.y - i), color), dsp);
		draw_line(&mlx->img, npt2(ft_nivec2(tr.x + i, tr.y - i), color),
			npt2(ft_nivec2(crns[1].x + i, crns[1].y + i), color), dsp);
		draw_line(&mlx->img, npt2(ft_nivec2(crns[1].x + i, crns[1].y + i),
				color), npt2(ft_nivec2(bl.x - i, bl.y + i), color), dsp);
		draw_line(&mlx->img, npt2(ft_nivec2(bl.x - i, bl.y + i), color),
			npt2(ft_nivec2(crns[0].x - i, crns[0].y - i), color), dsp);
	}
}

// Draws a filled rectangle between two corners
void	draw_frect(t_mlxinfo *mlx, t_ivec2 crns[2], int color)
{
	t_ivec2	dsp[2];
	t_ivec2	curr;
	int		y;

	dsp[0] = ft_nivec2(0, 0);
	dsp[1] = ft_nivec2(mlx->w_dim.x, mlx->w_dim.y);
	y = crns[0].y;
	while (y <= crns[1].y)
	{
		curr = ft_nivec2(crns[0].x, y);
		draw_line(&mlx->img,
			npt2(curr, color),
			npt2(ft_nivec2(crns[1].x, y), color),
			dsp);
		y++;
	}
}
