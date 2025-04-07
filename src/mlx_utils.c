/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:06:35 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/07 18:14:36 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_imgd *img, int x, int y, int color)
{
	char	*dst;

	printf("%p %i %i %i %i\n", img->addr, x, y, img->line_length, img->bits_per_pixel);
	printf("%x\n", (y * img->line_length + x * (img->bits_per_pixel / 8)));
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	rgb_to_int(int r, int g, int b)
// {

// }



void	draw_line(t_imgd *img, t_point p1, t_point p2)
{
	int		cursor;
	float	a;
	float	b;

	cursor = (float)p1.x;
	a = (float)(p2.y - p1.y) / (float)(p2.x - p1.x);
	b = (float)p1.y - a * p1.x;
	printf ("cursor dir : %i\n", ft_sign(p2.x - p1.x));
	while (cursor != p2.x)
	{
		printf("x : %i, y: %i\n", cursor, a * cursor + b);
		my_mlx_pixel_put(img, cursor, a * cursor + b, 0xFFFFFF);
		cursor += ft_sign(p2.x - p1.x);
		printf ("cursor : %i\n", cursor);
	}
}
//a = (p2.y - p1.y) / (p2.x - p1.x) //COEF DIRECTEUR

//y = (3+x)/2 = 0.5 * 3 + 0.5x
//y = a * x + b
//y - a * x = b

//2 - 0.5 * 1 = 1.5
