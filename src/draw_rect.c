/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:37:35 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/28 17:37:30 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
static t_point2 new_pt2(t_ivec2 v2, int color)
{
	t_point2	pt;

	pt.v2 = v2;
	pt.color = color;
	return (pt);
}

static void draw_edge(t_imgd *img, t_ivec2 p1, t_ivec2 p2, t_ivec2 dsp)
{
	draw_line(img, new_pt2(p1, 0xFFFFFF), new_pt2(p2, 0xFFFFFF), dsp);
}

void	draw_rect(t_imgd *img, t_ivec2 crns[2], int width, t_ivec2 dsp)
{
	int		i;
	t_ivec2	top_right;
	t_ivec2	bottom_left;

	top_right = ft_nivec2(crns[1].x, crns[0].y);
	bottom_left = ft_nivec2(crns[0].x, crns[1].y);
	i = -1;
	while (++i < width)
	{
		draw_edge(img, ft_nivec2( crns[0].x - i,  crns[0].y - i),
			ft_nivec2(top_right.x + i, top_right.y - i), dsp);
		draw_edge(img, ft_nivec2(top_right.x + i, top_right.y - i),
			ft_nivec2(crns[1].x + i, crns[1].y + i), dsp);
		draw_edge(img, ft_nivec2(crns[1].x + i, crns[1].y + i),
			ft_nivec2(bottom_left.x - i, bottom_left.y + i), dsp);
		draw_edge(img, ft_nivec2(bottom_left.x - i, bottom_left.y + i),
			ft_nivec2( crns[0].x - i,  crns[0].y - i), dsp);
	}
}
