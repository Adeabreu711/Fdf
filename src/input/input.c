/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:46:06 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 02:36:59 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"
#include "X11/keysym.h"

// Set up event handlers for window close, key press, and mouse click
void	receive_inputs(t_fdf *fdf)
{
	mlx_hook(fdf->mlx.window, 17, 0, close_window, fdf);
	mlx_hook(fdf->mlx.window, 2, 1L << 0, key_hook, fdf);
	mlx_hook(fdf->mlx.window, 4, 1L << 2, mouse_hook, fdf);
}

// Handle mouse input for zooming in and out
int	mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	button_scale(button, fdf);
	return (0);
}

// Handle key press events for various actions (color, height, etc.)
int	key_hook(int keycode, t_fdf *fdf)
{
	if (key_color(keycode, fdf)
		|| key_height(keycode, fdf)
		|| key_offset(keycode, fdf)
		|| key_render(keycode, fdf)
		|| key_show_tri(keycode, fdf))
		return (0);
	if (fdf->cam.ctrl.prj_id != 2)
		key_rotation(keycode, fdf);
	if (keycode == XK_Escape)
		close_window(fdf);
	return (0);
}
