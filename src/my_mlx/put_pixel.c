/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 02:25:46 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 19:31:59 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Checks if the given coordinates are within the screen bounds
static int	is_in_screen(t_ivec2 v2, t_ivec2 dsp[2])
{
	if (v2.x > dsp[0].x && v2.x < dsp[1].x
		&& v2.y > dsp[0].y && v2.y < dsp[1].y)
		return (1);
	return (0);
}

// Puts a pixel in the image at the given coordinates and color
void	put_pixel(t_imgd *img, t_ivec2 v2, int color, t_ivec2 dsp[2])
{
	char	*dst;

	if (!is_in_screen(v2, dsp))
		return ;
	dst = img->addr
		+ (v2.y * img->line_length + v2.x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
