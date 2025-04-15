/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:50 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/15 20:58:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <fcntl.h>

#include "my_mlx.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_string_builder.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/color.h"
#include "../libft/includes/vector.h"

typedef struct	s_cam
{
	int			scale;
	t_ivec2		offset;
	t_point2	*pts;
}	t_cam;

typedef struct	s_map
{
	int		size;
	int		row_len;
	t_point3	*pts;
}	t_map;

t_ivec2		project_flat(t_ivec3 v3);
void		init_cam(t_map map, t_ivec2 w_dim, t_cam cam);
t_ivec2		get_center_offset(t_map map, t_ivec2 w_dim);

void		scale_map(t_map *map, float scale);
int			display_points(t_imgd *img, t_map map);

int			parse_map(int fd, t_map *map);
t_point3		*get_points(char *r_map, int map_size, int raw_len);

void		debug_points(t_point3 *points);

#endif
