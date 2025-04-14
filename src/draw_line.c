/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:31:42 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/14 19:55:26 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_descending(t_imgd *img, t_point p1, t_point p2);
static void	draw_ascending(t_imgd *img, t_point p1, t_point p2);

void	draw_line(t_imgd *img, t_point p1, t_point p2)
{

	if (ft_abs(p2.y - p1.y) > ft_abs(p2.x - p1.x))
		return (draw_ascending(img, p1, p2));
	draw_descending(img, p1, p2);
}

static void	draw_ascending(t_imgd *img, t_point p1, t_point p2)
{
	int		cursor;
	float	a;
	float	b;

	cursor = (float)p1.y;
	a = (float)(p2.x - p1.x) / (float)(p2.y - p1.y);
	b = (float)p1.x - a * p1.y;
	// printf ("expected : (%i, %i) (%i, %i)\n", p1.x, p1.y, p2.x, p2.y);
	while (cursor != p2.y + ft_sign(p2.y - p1.y))
	{
		// if (cursor == p2.y + ft_sign(p2.y - p1.y) - ft_sign(p2.y - p1.y) || cursor == p1.y)
		// 	printf("draw at (%f, %i)\n", a * cursor + b, cursor);

		put_pixel(img, a * cursor + b, cursor, 0xFFFFFF);
		cursor += ft_sign(p2.y - p1.y);
	}
	// printf ("\n");
}

static void	draw_descending(t_imgd *img, t_point p1, t_point p2)
{
	int		cursor;
	float	a;
	float	b;

	cursor = (float)p1.x;
	a = (float)(p2.y - p1.y) / (float)(p2.x - p1.x);
	b = (float)p1.y - a * p1.x;
	// printf ("expected : (%i, %i) (%i, %i)\n", p1.x, p1.y, p2.x, p2.y);
	while (cursor != p2.x + ft_sign(p2.x - p1.x))
	{
		// if (cursor == p2.x + ft_sign(p2.x - p1.x) - ft_sign(p2.x - p1.x) || cursor == p1.x)
		// 	printf("draw at (%i, %f)\n", cursor, a * cursor + b);
		put_pixel(img, cursor, a * cursor + b, 0xFFFFFF);
		cursor += ft_sign(p2.x - p1.x);
	}
	// printf ("\n");
}
