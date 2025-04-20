/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:06:15 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/20 03:33:03 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_map_point(char *r_map, int i)
{
	if (!ft_is_space(r_map[i]) && (ft_is_sign(r_map[i]) 
			|| ft_isdigit(r_map[i])) && (!i || ft_is_space(r_map[i - 1])))
			return (1);
	return (0);
}

int	check_hexa_color(char *color)
{
	int	i;

	i = 2;
	if (!color || ft_strncmp(color, "0x", 2))
		return (0);
	while (ft_strchr("0123456789ABCDEF", color[i]))
		i++;
	if (ft_is_space(color[i]) && i > 2)
		return (i);
	return (0);
}

int	get_info_format(char *info)
{
	int	i;

	i = 0;
	if (ft_is_sign(info[i]))
		i++;
	if (!ft_isdigit(info[i]))
		return (0);
	while (ft_isdigit(info[i]))
		i++;
	if (!info[i] || ft_is_space(info[i]))
		return (1);
	if (info[i++] == ',')
	{
		if (check_hexa_color(info + i))
			return (2);
	}
	return (0);
}

t_point3	get_point_info(char *info, int id, int line_size)
{
	int			i;
	t_point3	point;
	int			format;

	i = 0;
	format = get_info_format(info);
	if (!format)
	{
		printf("BAD FORMAT\n");
		point.v3.x = -1;
		return (point);
	}
	point.v3.x = id % line_size;
	point.v3.y = id / line_size;
	point.v3.z = ft_atoi(info);
	point.color = 0xFFFFFF;
	// printf("x : %i, y : %i, z : %i\n", point.x, point.y, point.z);
	if (format == 1)
		return (point);
	while (info[i] != ',')
		i++;
	point.color = ft_atoi_base(info + i + 3, "0123456789ABCDEF");
	return (point);
}

t_point3	*get_points(char *r_map, int map_size, int raw_len)
{
	int		i;
	int		j;
	t_point3	*points;

	i = -1;
	j = 0;
	points = ft_calloc(map_size + 1, sizeof(t_point3));
	if (!points)
		return (NULL);
	while (r_map[++i])
	{
		if (ft_is_space(r_map[i]))
			continue ;
		else if (is_map_point(r_map, i))
			{
				points[j] = get_point_info(r_map + i, j, raw_len);
				if (points[j].v3.x == -1)
					return (free(points), NULL);
				j++;
			}
	}
	return (points);
}
