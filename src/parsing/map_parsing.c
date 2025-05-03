/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:51:52 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/03 14:46:19 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	*get_map(int fd);
static int	check_valid_size(int count, int line_size);
static int	get_map_size(char *r_map, int *out_raw_len);

// Parse map from file, fill map struct, return 1 if success, 0 if fail
int	parse_map(int fd, t_map *map)
{
	char	*r_map;

	if (fd < 3)
		return (ft_printf(ERR_INVALID_FD), 0);
	r_map = get_map(fd);
	if (!r_map)
		return (ft_printf(ERR), 0);
	r_map = ft_strupcase(r_map, "x");
	if (!is_map_valid(r_map))
		return (free(r_map), 0);
	map->size = get_map_size(r_map, &map->row_len);
	if (map->row_len == 0)
	{
		if (!adapt_map(&r_map, map))
			return (free(r_map), 0);
	}
	map->pts = get_points(r_map, map->size, map->row_len);
	if (!map->pts)
		return (ft_printf(ERR), free(r_map), 0);
	return (free(r_map), 1);
}

// Reads the full map from a file and returns it as a string
static char	*get_map(int fd)
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

// Check if all rows have same size, return valid size or 0
static int	check_valid_size(int count, int line_size)
{
	static int	line_count = 1;

	if (line_size == -1)
	{
		line_count = 1;
		return (count);
	}
	line_count++;
	if (line_size * 10 != (count * 10) / line_count)
		return (0);
	return (line_size);
}

// Get map size and row length, return 1 if valid, 0 if error
static int	get_map_size(char *r_map, int *out_raw_len)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	*out_raw_len = -1;
	while (r_map[++i])
	{
		if (r_map[i] == '\n')
			*out_raw_len = check_valid_size(count, *out_raw_len);
		if (!*out_raw_len)
			return (count);
		if (is_map_point(r_map, i))
			count++;
	}
	return (count);
}
