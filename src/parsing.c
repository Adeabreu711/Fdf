/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:06:15 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/09 20:49:25 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int	points_len(char *map)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		if (ft_is_space(map[i]))
			continue ;
		else if ((ft_is_sign(map[i]) || ft_isdigit(map[i]))
			&& (ft_is_space(map[i - 1]) || !map[i]))
			{
				printf("bruh\n");
				count++;
			}
	}
	return (count);
}

t_point	**get_points(char *map)
{
	t_point		**points;
}

t_point	**parsing_map(int fd)
{
	char		*map;
	t_point		**points;
	int			size;

	map = get_map(fd);
	if (!map)
		return (NULL);
	printf("%s\n", map);
	printf ("points_lenn : %i\n", points_len(map));
}
