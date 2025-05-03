/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adapt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 23:03:24 by alex              #+#    #+#             */
/*   Updated: 2025/05/03 14:44:31 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_col_len(char *r_map);
static int	get_ms_points(char *r_map, int *row_max, int is_row_max);
static int	fill_row(char *n_map, int pad);
static char	*fix_map(char *n_map, char *r_map, int row_max);

// Converts the given invalid map into a valid one by filling in missing values
// Returns 0 on failure, 1 on success
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
		return (ft_printf(ERR), 0);
	fix_map(n_map, *r_map, map->row_len);
	free(*r_map);
	*r_map = n_map;
	map->size = get_col_len(*r_map) * map->row_len;
	return (1);
}

// Returns the number of columns encountered.
static int	get_col_len(char *r_map)
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

// Calculates and returns the number of missing points in rows
// while updating row_max with the maximum row length encountered
static int	get_ms_points(char *r_map, int *row_max, int is_row_max)
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

// Fills a row with padding and returns the number of characters written
static int	fill_row(char *n_map, int pad)
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

// Fixes the map by filling rows with missing points; Returns the updated map
static char	*fix_map(char *n_map, char *r_map, int row_max)
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
