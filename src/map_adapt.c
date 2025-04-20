/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adapt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 23:03:24 by alex              #+#    #+#             */
/*   Updated: 2025/04/20 03:08:16 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int	get_col_len(char *r_map)
// {
// 	int	i;
// 	int	col_len;
// 	int	is_valid;

// 	i = -1;
// 	is_valid = 0;
// 	col_len = 0;
// 	while (r_map[++i])
// 	{
// 		if (r_map[i] == '\n' && is_valid)

// 	}
// }

t_ivec2	get_raw_max(char *r_map, int col_len)
{
	int		raw_max;
	t_ivec2	msg_pts;
	int		i;

	i = -1;
	while (r_map[++i])
	{
		// if (raw_max = )
		// else if (is_map_pt(r_map, i))
		// 		count++;
	}
	return (msg_pts);
}

// char	*fill_map(char *n_map, int size)
// {
// 	int		i;
// 	char	*n_map;
	
// 	i = 0;
// 	n_map = ft_calloc(size + 1, sizeof(char));
// 	if (!n_map)
// 		return (NULL);
// }

t_map	*adapt_map(char **r_map, t_map *map)
{
	char	*n_map;
	int		ms_pts;
	int		fd_size;

	printf("ADAPTING MAP\n");
	if (!*r_map)
		return (0);
	// map->size = get_new_map_size(*r_map, &map->row_len, fd_size);
	// n_map = fill_map(*n_map, fd_size);


	return (map);
	
}
