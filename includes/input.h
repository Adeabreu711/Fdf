/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:38:14 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/27 15:52:51 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "fdf.h"

//___________INPUT___________
//_____________________________

//input_height.c

int			key_height(int keycode, t_fdf *fdf);

//input_offset.c

int			key_offset(int keycode, t_fdf *fdf);

//input_render.c

int			key_render(int keycode, t_fdf *fdf);

//input_rotation.c (1 & 2)

int			key_rotation(int keycode, t_fdf *fdf);
int			rotate_projection(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr);
int			rotate_top_right(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr);
int			rotate_bot_left(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr);
int			rotate_bot_right(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr);
int			rotate_top_left(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr);

//input_scale.c

int			zoom_in(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr);
int			zoom_out(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr);

//input_utils.c

int			close_window(t_fdf *fdf);
void		apply_rotation(t_map map, t_cam *cam, char axis, float angle);
void		apply_projection(t_map mp, t_cam *cm, t_ivec2(*f)(t_cam, t_fvec3));
void		reset_rotation(t_map map, t_cam *cam);
int			refresh_projection(t_mlxinfo *mlx, t_map map, t_cam *cam, t_rdr rdr);

//input.c

int			key_hook(int keycode, t_fdf *fdf);
int			mouse_hook(int button, int x, int y, t_fdf *fdf);

#endif
