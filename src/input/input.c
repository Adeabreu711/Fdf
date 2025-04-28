/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:46:06 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/28 13:44:31 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"
#include "X11/keysym.h"

int	mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom_in(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	else if (button == 5)
		zoom_out(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	return (0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	key_color(keycode, fdf);
	key_height(keycode, fdf);
	key_offset(keycode, fdf);
	key_render(keycode, fdf);
	key_show_tri(keycode, fdf);
	if (fdf->cam.prj_id != 2)
		key_rotation(keycode, fdf);
	if (keycode == XK_Escape)
		close_window(fdf);
	return (0);
}
