/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:54:49 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/03 15:15:52 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "fdf.h"

# define ERR_EMPTY_LINE "\033[31merror :\033[0m empty line in file\n"
# define ERR_INVALID_PT "\033[31merror :\033[0m invalid point in file\n"
# define ERR_INVALID_CHAR "\033[31merror :\033[0m invalid character in file\n"
# define ERR_INVALID_FD "\033[31merror :\033[0m invalid file\n"
# define ERR_INVALID_SIZE "\033[31merror :\033[0m map size to small\n"
# define ERR "\033[31merror\033[0m\n"

typedef struct s_map
{
	int			size;
	int			row_len;
	t_point3	*pts;
}	t_map;

//___________PARSING___________

//map_parsing.c

int			parse_map(int fd, t_map *map);

//point_parsing.c

t_point3	*get_points(char *r_map, int map_size, int raw_len);
int			check_hexa_color(char *color);
int			is_map_point(char *r_map, int i);

//map_checker.c

int			is_map_valid(char *r_map);

//___________MAP_CUSTOM__________

int			adapt_map(char **r_map, t_map *map);

#endif
