/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:50 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/19 00:52:00 by alex             ###   ########.fr       */
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
	float		scale;
	t_ivec2		offset;
	t_ivec2		dsp;
	t_point2	*pts;
}	t_cam;

typedef struct	s_map
{
	int		size;
	int		row_len;
	t_point3	*pts;
}	t_map;

t_ivec2		project_flat(t_ivec3 v3);
t_ivec2		project_iso(t_cam cam, t_ivec3 v3);
t_cam		init_cam(t_map map, t_ivec2 dsp, t_ivec2(*f)(t_cam, t_ivec3));
t_ivec2		get_center_offset(t_map map, t_cam cam, t_ivec2(*f)(t_cam, t_ivec3));

void		scale_cam(t_map *map, float scale);
int			display_points(t_imgd *img, t_cam cam, t_map map);

t_ivec2		*get_corners(t_map map, t_cam cam, t_ivec2(*f)(t_cam, t_ivec3));
t_ivec2		*get_min_max(t_map map, t_ivec2(*f)(t_cam, t_ivec3));
void		free_cam(t_cam *cam);
t_cam		new_cam(t_point2 *pts, t_ivec2 dsp);

int			parse_map(int fd, t_map *map);
t_point3	*get_points(char *r_map, int map_size, int raw_len);

void		debug_center(t_mlxinfo mlx);
void		debug_map(t_map map, int show_pts);
void		debug_cam(t_cam cam, t_map map, int show_pts);
void		debug_prj_center(t_mlxinfo mlx, t_map map, t_cam cam, t_ivec2(*f)(t_cam, t_ivec3));
void		debug_corners(t_mlxinfo mlx, t_cam cam, t_map map);

#endif
