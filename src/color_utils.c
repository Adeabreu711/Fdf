/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 00:39:00 by alex              #+#    #+#             */
/*   Updated: 2025/04/23 15:47:12 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color	int_to_rgb(int color)
{
	t_color	c;

	c.r = (color >> 16) & 0xFF;
	c.g = (color >> 8) & 0xFF;
	c.b = color & 0xFF;
	return (c);
}

int	rgb_to_int(t_color c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}

int	lerp_color(int color1, int color2, float grad)
{
	t_color	c1;
	t_color	c2;
	t_color	result;

	c1 = int_to_rgb(color1);
	c2 = int_to_rgb(color2);
	result.r = c1.r + (int)((c2.r - c1.r) * grad);
	result.g = c1.g + (int)((c2.g - c1.g) * grad);
	result.b = c1.b + (int)((c2.b - c1.b) * grad);
	return (rgb_to_int(result));
}
