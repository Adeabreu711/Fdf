/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:50 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/28 17:07:11 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "my_mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_string_builder.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/color.h"
# include "../libft/includes/vector.h"

# define PRJ_S 3
# define COLOR_S 3

typedef struct s_stgs
{
	t_ivec2		dsp;
	t_fvec2		lmt_scale;
	t_fvec2		lmt_offset;
}	t_stgs;

typedef struct s_cam
{
	int			prj_id;
	int			color_id;
	int			show_tri;
	float		height;
	float		scale;
	t_ivec2		offset;
	t_fvec3		rotation;
	t_fvec3		*v_rota;
	t_point2	*pts;
	t_stgs		stgs;
}	t_cam;

typedef struct s_map
{
	int			size;
	int			row_len;
	t_point3	*pts;
}	t_map;

typedef struct s_rdr
{
	t_ivec2		(*prj[PRJ_S])(t_cam, t_fvec3);
	t_ivec3		c_grad[COLOR_S];
}	t_rdr;

typedef struct s_fdf
{
	t_cam		cam;
	t_map		map;
	t_rdr		rdr;
	t_mlxinfo	mlx;
}	t_fdf;

//___________CAMERA___________

//camera.c

t_cam		init_cam(t_map map, t_ivec2 dsp, t_rdr rdr);
t_ivec2		get_center_offset(t_cam cam, t_ivec2 *min_max);

//camera_utils.c

t_cam		new_cam(t_point2 *pts, t_ivec2 dsp);
void		free_cam(t_cam *cam);
t_ivec2		*get_min_max_xy(t_map map, t_ivec2(*f)(t_cam, t_fvec3));
t_ivec2		get_min_max_z(t_map map);

//projection.c

void		init_projections(t_rdr *rdr);
t_ivec2		project_iso(t_cam cam, t_fvec3 v3);
t_ivec2		project_cavalier(t_cam cam, t_fvec3 v3);

//rotation.c

t_fvec3		rotate(t_fvec3 v3, float rota, char axis);

//display_points.c

int			display_points(t_imgd *img, t_cam cam, t_map map);

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

//color_map.c

void		color_map(t_map map, t_cam *cam, t_ivec3 colors);
void		init_gradients(t_rdr *rdr);
void		get_dflt_color(t_map map, t_cam *cam);

//UI
void		draw_ui_rect(t_imgd *img, t_ivec2 dim, float w_sf, t_ivec2 dsp);
float		get_window_sf(void);

//___________DEBUG___________
//___________________________

void		debug_center(t_mlxinfo mlx);
void		debug_map(t_map map, int show_pts);
void		debug_cam(t_cam cam, t_map map, int show_pts);
void		debug_prj_center(t_mlxinfo mlx, t_map map, t_cam cam, t_ivec2(*f)(t_cam, t_ivec3));
void		debug_corners(t_mlxinfo mlx, t_cam cam, t_map map);

#endif
