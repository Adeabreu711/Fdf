/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:58:21 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 00:17:17 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA__H
# define CAMERA__H

# include "fdf.h"

# define PRJ_S 3
# define COLOR_S 3

typedef struct s_stgs
{
	t_ivec2		dsp[2];
	t_fvec2		lmt_scale;
	t_fvec2		lmt_offset;
}	t_stgs;

typedef struct s_ctrl
{
	int			prj_id;
	int			color_id;
	int			show_tri;
	float		height;
	float		scale;
	t_ivec2		offset;
	t_fvec3		rotation;
}	t_ctrl;

typedef struct s_cam
{
	t_fvec3		*v_rota;
	t_point2	*pts;
	t_stgs		stgs;
	t_ctrl		ctrl;
}	t_cam;

typedef struct s_rdr
{
	t_ivec2		(*prj[PRJ_S])(t_ctrl, t_fvec3);
	t_ivec3		c_grad[COLOR_S];
}	t_rdr;


//___________CAMERA___________

//camera.c

t_cam		init_cam(t_map map, t_ivec2 w_dim, t_ivec2 size, t_rdr rdr);
t_ivec2		get_center_offset(t_cam cam, t_ivec2 *min_max);
void		assign_display(t_ivec2 w_dim, t_ivec2 size, t_ivec2	dsp[2]);

//camera_utils.c

t_cam		new_cam(t_point2 *pts, t_ivec2 tl_crn, t_ivec2 br_crn);
void		free_cam(t_cam *cam);
void		set_min_max_xy(t_map map, t_ivec2 mm[4], t_ivec2(*f)(t_ctrl, t_fvec3));
t_ivec2		get_min_max_z(t_map *map);

//projection.c

void		init_projections(t_rdr *rdr);
t_ivec2		project_iso(t_ctrl cam, t_fvec3 v3);
t_ivec2		project_cavalier(t_ctrl cam, t_fvec3 v3);

//rotation.c

t_fvec3		rotate(t_fvec3 v3, float rota, char axis);

//display_points.c

int			display_points(t_imgd *img, t_cam *cam, t_map *map);

// //___________MAP_CUSTOM__________
// //_______________________________

// //color_map.c

void		color_map(t_map *map, t_cam *cam, t_ivec3 colors);
void		init_gradients(t_rdr *rdr);
void		get_dflt_color(t_map *map, t_cam *cam);

#endif
