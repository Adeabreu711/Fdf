/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:31:42 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/21 23:45:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_descending(t_imgd *img, t_point2 p1, t_point2 p2);
static void	draw_ascending(t_imgd *img, t_point2 p1, t_point2 p2);

//draw a line between the two given points.
void	draw_line(t_imgd *img, t_point2 p1, t_point2 p2)
{
	if (ft_abs(p2.v2.y - p1.v2.y) > ft_abs(p2.v2.x - p1.v2.x))
		return (draw_ascending(img, p1, p2));
	draw_descending(img, p1, p2);
}

//draw line taking the y axis as increment.
static void	draw_ascending(t_imgd *img, t_point2 p1, t_point2 p2)
{
	int		cursor;
	float	a;
	float	b;

	cursor = (float)p1.v2.y;
	a = (float)(p2.v2.x - p1.v2.x) / (float)(p2.v2.y - p1.v2.y);
	b = (float)p1.v2.x - a * p1.v2.y;
	while (cursor != p2.v2.y + ft_sign(p2.v2.y - p1.v2.y))
	{
		put_pixel(img, a * cursor + b, cursor, p1.color);
		cursor += ft_sign(p2.v2.y - p1.v2.y);
	}
}

//draw line taking the x axis as increment.
static void	draw_descending(t_imgd *img, t_point2 p1, t_point2 p2)
{
	int		cursor;
	float	a;
	float	b;

	cursor = (float)p1.v2.x;
	a = (float)(p2.v2.y - p1.v2.y) / (float)(p2.v2.x - p1.v2.x);
	b = (float)p1.v2.y - a * p1.v2.x;
	while (cursor != p2.v2.x + ft_sign(p2.v2.x - p1.v2.x))
	{
		put_pixel(img, cursor, a * cursor + b, p1.color);
		cursor += ft_sign(p2.v2.x - p1.v2.x);
	}
}
