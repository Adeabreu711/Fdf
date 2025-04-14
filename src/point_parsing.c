/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:06:15 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/14 19:43:24 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_hexa_color(char *color)
{
	int	i;

	i = 2;
	if (!color || ft_strncmp(color, "0x", 2))
		return (0);
	while (ft_strchr("0123456789ABCDEF", color[i]))
		i++;
	if (i == 8)
		return (1);
	return (0);
}

int	check_info(char *info)
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

t_point	get_point_info(char *info, int id, int line_size)
{
	int		i;
	t_point	point;
	int		format;

	i = 0;
	format = check_info(info);
	if (!format)
	{
		point.x = -1;
		return (point);
	}
	point.x = id % line_size;
	point.y = id / line_size;
	point.z = ft_atoi(info);
	point.color = 0xFFFFFF;
	// printf("x : %i, y : %i, z : %i\n", point.x, point.y, point.z);
	if (format == 1)
		return (point);
	while (info[i] != ',')
		i++;
	point.color = ft_atoi_base(info + i + 3, "0123456789ABCDEF");
	return (point);
}

t_point	*get_points(char *r_map, int map_size, int raw_len)
{
	int		i;
	int		j;
	t_point	*points;

	i = -1;
	j = 0;
	points = ft_calloc(map_size + 1, sizeof(t_point));
	if (!points)
		return (NULL);
	while (r_map[++i])
	{
		if (ft_is_space(r_map[i]))
			continue ;
		else if ((ft_is_sign(r_map[i]) || ft_isdigit(r_map[i]))
			&& (!i || ft_is_space(r_map[i - 1])))
			{
				points[j] = get_point_info(r_map + i, j, raw_len);
				if (!points[j].x == -1)
					return (free(points), NULL);
				j++;
			}
	}
	return (points);
}
