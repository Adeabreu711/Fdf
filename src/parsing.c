/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:06:15 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/11 19:52:45 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// t_point	get_point_info(char *info)
// {
// 	ft_atoi(*info);
// }

t_point	*get_points(char *map, int map_size)
{
	int		i;
	int		j;
	t_point	*points;

	i = -1;
	j = 0;
	points = ft_calloc(map_size + 1, sizeof(t_point));
	if (!points)
		return (NULL);

	// while (map[++i])
	// {
	// 	if (ft_is_space(map[i]))
	// 		continue ;
	// 	else if ((ft_is_sign(map[i]) || ft_isdigit(map[i]))
	// 		&& (!i || ft_is_space(map[i - 1])))
	// 		points = get_point_info(map + i);
	// }
	return (points);
}

t_point	*parsing_map(int fd)
{
	char		*map;
	t_point		*points;
	int			map_size;
	int			line_size;

	line_size = 0;
	map = get_map(fd);
	if (!map)
		return (NULL);
	map_size =  get_map_size(map, &line_size);
	// if (!map_size || line_size == 0)
	// 	return (NULL);
	printf("%s\n", map);
	printf ("points_len : %i\n", map_size);
	get_points(map, map_size);
}
