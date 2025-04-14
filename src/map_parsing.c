/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:51:52 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/14 19:47:34 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define ERROR 0

char	*get_map(int fd)
{
	t_sbuild	*sb;
	char		*r_map;
	char		*line;

	line = NULL;
	sb = ft_sbnew("");
	if (!sb)
		return (NULL);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		ft_sb_addstr(&sb, line, ft_strlen(line));
		free(line);
	}
	r_map = ft_sb_build(sb);
	ft_get_next_line(-1);
	ft_sbclear(&sb);
	close(fd);
	return (r_map);
}

static int	check_valid_size(int count, int line_size)
{
	static int line_count = 1;

	if (line_size == -1)
	{
		line_count = 1;
		return (count);
	}
	line_count++;
	if (line_size * 10 != (count * 10) / line_count)
		return (ERROR);
	return (line_size);
}

int	get_map_size(char *r_map, int *out_raw_len)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	*out_raw_len = -1;
	while (r_map[++i])
	{
		if (ft_is_space(r_map[i]))
		{
			if (r_map[i] == '\n')
				*out_raw_len= check_valid_size(count, *out_raw_len);
			if (!*out_raw_len)
				return (ERROR);
		}
		else if ((ft_is_sign(r_map[i]) || ft_isdigit(r_map[i]))
			&& (!i || ft_is_space(r_map[i - 1])))
				count++;
	}
	return (count);
}

int	parse_map(int fd, t_map *map)
{
	char	*r_map;
	int		map_size;
	int		line_size;

	line_size = 0;
	r_map = get_map(fd);
	if (!r_map)
		return (0);
	map->size =  get_map_size(r_map, &map->row_len);
	printf("%s\n", r_map);
	printf("map size : %i, line_size : %i\n", map->size, map->row_len);
	if (!map->size || map->row_len == 0)
		return (free(r_map), 0);
	map->pts = get_points(r_map, map->size, map->row_len);
	if (!map->pts)
		return (free(r_map), 0);
	free(r_map);
	return (1);
}
