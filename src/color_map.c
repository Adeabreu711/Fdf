/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:12:53 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 19:33:16 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_gradients(t_rdr *rdr)
{
	rdr->c_grad[0] = ft_nivec3(0x1f2041, 0x4b3f72, 0xffc857);
	rdr->c_grad[1] = ft_nivec3(0x001437, 0x2AC9F9, 0x56F1FF);
	rdr->c_grad[2] = ft_nivec3(0x000000, 0x9D0191, 0xFD3A69);
}

void	color_map(t_map *map, t_cam *cam, t_ivec3 colors)
{
	int		i;
	t_ivec2	mm_z;
	float	grad;

	i = -1;
	mm_z = get_min_max_z(map);
	while (++i < map->size)
	{
		if (mm_z.y - mm_z.x == 0)
			grad = 0.5f;
		else
			grad = (float)(map->pts[i].v3.z - mm_z.x) / (mm_z.y - mm_z.x);
		if (grad < 0.5f)
			cam->pts[i].color = lerp_color(colors.x, colors.y, grad * 2.0f);
		else
			cam->pts[i].color = lerp_color(colors.y,
					colors.z, (grad - 0.5f) * 2.f);
	}
}

void	get_dflt_color(t_map *map, t_cam *cam)
{
	int	i;

	i = -1;
	while (++i < map->size)
		cam->pts[i].color = map->pts[i].color;
}
