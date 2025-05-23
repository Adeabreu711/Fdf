/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:31:42 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 19:23:51 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_des(t_imgd *img, t_point2 p1, t_point2 p2, t_ivec2 dsp[2]);
static void	draw_asc(t_imgd *img, t_point2 p1, t_point2 p2, t_ivec2 dsp[2]);

// Draws a line between two points, axis chosen by steepness
void	draw_line(t_imgd *img, t_point2 p1, t_point2 p2, t_ivec2 dsp[2])
{
	if (ft_abs(p2.v2.y - p1.v2.y) > ft_abs(p2.v2.x - p1.v2.x))
		return (draw_asc(img, p1, p2, dsp));
	draw_des(img, p1, p2, dsp);
}

// Draws a steep line using vertical (Y-axis) increments
static void	draw_asc(t_imgd *img, t_point2 p1, t_point2 p2, t_ivec2 dsp[2])
{
	int		cursor;
	int		color;
	float	a;
	float	b;

	cursor = (float)p1.v2.y;
	a = (float)(p2.v2.x - p1.v2.x) / (float)(p2.v2.y - p1.v2.y);
	b = (float)p1.v2.x - a * p1.v2.y;
	while (cursor != p2.v2.y + ft_sign(p2.v2.y - p1.v2.y))
	{
		color = lerp_color(p1.color, p2.color, (float)(cursor - p1.v2.y)
				/ (float)(p2.v2.y - p1.v2.y));
		put_pixel(img, ft_nivec2(a * cursor + b, cursor), color, dsp);
		cursor += ft_sign(p2.v2.y - p1.v2.y);
	}
}

// Draws a shallow line using horizontal (X-axis) increments
static void	draw_des(t_imgd *img, t_point2 p1, t_point2 p2, t_ivec2 dsp[2])
{
	float	cursor;
	int		color;
	float	a;
	float	b;

	color = 0;
	cursor = (float)p1.v2.x;
	a = (float)(p2.v2.y - p1.v2.y) / (float)(p2.v2.x - p1.v2.x);
	b = (float)p1.v2.y - a * p1.v2.x;
	while (cursor != p2.v2.x + ft_sign(p2.v2.x - p1.v2.x))
	{
		color = lerp_color(p1.color, p2.color, (float)(cursor - p1.v2.x)
				/ (float)(p2.v2.x - p1.v2.x));
		put_pixel(img, ft_nivec2(cursor, a * cursor + b), color, dsp);
		cursor += ft_sign(p2.v2.x - p1.v2.x);
	}
}
