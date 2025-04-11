/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:51:52 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/11 19:53:32 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define ERROR 0

char	*get_map(int fd)
{
	t_sbuild	*sb;
	char		*map;
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
	map = ft_sb_build(sb);
	ft_get_next_line(-1);
	ft_sbclear(&sb);
	close(fd);
	return (map);
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

int	get_map_size(char *map, int *out_line_size)
{
	int	i;
	int	count;
	int	line_size;
	int	line_count;

	i = -1;
	count = 0;
	line_size = -1;
	line_count = 0;
	while (map[++i])
	{
		if (ft_is_space(map[i]))
		{
			if (map[i] == '\n')
				line_size = check_valid_size(count, line_size);
			if (!line_size)
				return (ERROR);
		}
		else if ((ft_is_sign(map[i]) || ft_isdigit(map[i]))
			&& (!i || ft_is_space(map[i - 1])))
				count++;
	}
	return (count);
}
