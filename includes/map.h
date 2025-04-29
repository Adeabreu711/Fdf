/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:54:49 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 18:18:48 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "fdf.h"

typedef struct s_map
{
	int			size;
	int			row_len;
	t_point3	*pts;
}	t_map;

//___________PARSING___________
//_____________________________

//map_parsing.c

int			parse_map(int fd, t_map *map);

//point_parsing.c

t_point3	*get_points(char *r_map, int map_size, int raw_len);
int			check_hexa_color(char *color);
int			is_map_point(char *r_map, int i);

//map_checker.c

int			is_map_valid(char *r_map);

//___________MAP_CUSTOM__________
//_______________________________

int			adapt_map(char **r_map, t_map *map);

#endif
