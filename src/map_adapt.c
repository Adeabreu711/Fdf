/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adapt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 23:03:24 by alex              #+#    #+#             */
/*   Updated: 2025/04/21 21:53:42 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//return the number of columns encountred.
int	get_col_len(char *r_map)
{
	int	i;
	int	col_len;

	i = -1;
	col_len = 0;
	while (r_map[++i])
	{
		if (r_map[i] == '\n' || !r_map[i + 1])
			col_len++;
	}
	return (col_len);
}

//out the max points in a row in the first half and
//return the number of missing points in the second. 
int	get_ms_points(char *r_map, int *row_max, int is_row_max)
{
	int		ms_pts;
	int		row_size;
	int		i;

	i = -1;
	row_size = 0;
	ms_pts = 0;
	while (r_map[++i])
	{
		if (r_map[i] == '\n')
		{
			if (row_size > *row_max && !is_row_max)
				*row_max = row_size ;
			if (is_row_max)
				ms_pts += *row_max - row_size;
			row_size = 0;
		}
		else if (is_map_point(r_map, i))
			row_size++;
	}
	if (!is_row_max)
		return (get_ms_points(r_map, row_max, 1));
	return (ms_pts);
}

//fill the given row of points according to the given padding
//return the number of char writed.
int	fill_row(char *n_map, int pad)
{
	int	i;

	i = 0;
	while (pad--)
	{
		n_map[i++] = ' ';
		n_map[i++] = '0';
	}
	return (i);
}

//fill the given row of points according to the given padding.
char	*fix_map(char *n_map, char *r_map, int row_max)
{
	int		i;
	int		j;
	int		row_size;

	i = -1;
	j = 0;
	row_size = 0;
	while (r_map[++i])
	{
		if (r_map[i] == '\n')
		{
			if (row_size < row_max)
				j += fill_row(&(n_map[j]), row_max - row_size);
			n_map[j++] = r_map[i];
			row_size = 0;
		}
		else
			n_map[j++] = r_map[i];
		if (is_map_point(r_map, i))
			row_size++;
	}
	if (n_map[j - 1] == '\n')
		n_map[j - 1] = '\0';
	return (n_map);
}

//convert the given invalid readed map into a valid one.
//fill new map value.
//return 0 if fail, 1 if success.
int	adapt_map(char **r_map, t_map *map)
{
	char	*n_map;
	int		ms_pts;

	ms_pts = 0;
	map->row_len = 0;
	map->size = 0;
	ms_pts = get_ms_points(*r_map, &map->row_len, 0);
	n_map = ft_calloc(ft_strlen(*r_map) + ms_pts * 2 + 1, sizeof(char));
	if (!n_map)
		return (0);
	fix_map(n_map, *r_map, map->row_len);
	free(*r_map);
	*r_map = n_map;
	map->size = get_col_len(*r_map) * map->row_len;
	return (1);
}
