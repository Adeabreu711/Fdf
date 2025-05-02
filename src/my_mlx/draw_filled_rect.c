/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_filled_rect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 02:25:46 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/01 01:05:50 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_rect_bounds(t_ivec2 crns[2], t_ivec2 *start, t_ivec2 *end)
{
	if (crns[0].x < crns[1].x)
	{
		start->x = crns[0].x;
		end->x = crns[1].x;
	}
	else
	{
		start->x = crns[1].x;
		end->x = crns[0].x;
	}
	if (crns[0].y < crns[1].y)
	{
		start->y = crns[0].y;
		end->y = crns[1].y;
	}
	else
	{
		start->y = crns[1].y;
		end->y = crns[0].y;
	}
}

void	draw_frect(t_imgd *img, t_ivec2 crns[2], t_ivec2 dsp[2], int color)
{
	t_ivec2	start;
	t_ivec2	end;
	t_ivec2	curr;

	get_rect_bounds(crns, &start, &end);
	curr.y = start.y - 1;
	while (++curr.y <= end.y)
	{
		curr.x = start.x;
		while (curr.x <= end.x)
		{
			put_pixel(img, curr, color, dsp);
			curr.x++;
		}
	}
}
