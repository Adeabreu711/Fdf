/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:38:14 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 02:05:42 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "fdf.h"

//___________INPUT___________
//_____________________________

//input_color.c

int			key_color(int keycode, t_fdf *fdf);

//input_height.c

int			key_height(int keycode, t_fdf *fdf);

//input_offset.c

int			key_offset(int keycode, t_fdf *fdf);

//input_render.c

int			key_render(int keycode, t_fdf *fdf);

//input_rotation.c (1 & 2)

int			key_rotation(int keycode, t_fdf *fdf);
int			rotate_projection(t_fdf *fdf);
int			rotate_top_right(t_fdf *fdf);
int			rotate_bot_left(t_fdf *fdf);
int			rotate_bot_right(t_fdf *fdf);
int			rotate_top_left(t_fdf *fdf);

//input_scale.c

int			button_scale(int button, t_fdf *fdf);

//input_show_tri.c

int			key_show_tri(int keycode, t_fdf *fdf);

//input_utils.c

int			close_window(t_fdf *fdf);
void		apply_rotation(t_map *map, t_cam *cam, char axis, float angle);
void		apply_projection(t_map *map, t_cam *cam, t_prj_func f);
void		reset_rotation(t_map *map, t_cam *cam);
int			refresh_projection(t_fdf *fdf);

//input.c

void		receive_inputs(t_fdf *fdf);
int			key_hook(int keycode, t_fdf *fdf);
int			mouse_hook(int button, int x, int y, t_fdf *fdf);

#endif
