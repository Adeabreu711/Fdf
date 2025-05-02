/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:05:31 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 02:17:33 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

// Move camera to the left if not at camera limits
static int	translate_left(t_fdf *fdf)
{
	if (fdf->cam.ctrl.offset.x <= fdf->cam.stgs.lmt_offset_x.x)
		return (1);
	fdf->cam.ctrl.offset.x -= 5;
	refresh_projection(fdf);
	return (1);
}

// Move camera to the right if not at camera limits
static int	translate_right(t_fdf *fdf)
{
	if (fdf->cam.ctrl.offset.x >= fdf->cam.stgs.lmt_offset_x.y)
		return (1);
	fdf->cam.ctrl.offset.x += 5;
	refresh_projection(fdf);
	return (1);
}

// Move camera up if not at camera limits
static int	translate_up(t_fdf *fdf)
{
	if (fdf->cam.ctrl.offset.y <= fdf->cam.stgs.lmt_offset_y.x)
		return (1);
	fdf->cam.ctrl.offset.y -= 5;
	refresh_projection(fdf);
	return (1);
}

// Move camera down if not at camera limits
static int	translate_down(t_fdf *fdf)
{
	if (fdf->cam.ctrl.offset.y >= fdf->cam.stgs.lmt_offset_y.y)
		return (1);
	fdf->cam.ctrl.offset.y += 5;
	refresh_projection(fdf);
	return (1);
}

// Handle key inputs to move the camera in display
int	key_offset(int keycode, t_fdf *fdf)
{
	if (keycode == XK_d)
		return (translate_left(fdf));
	else if (keycode == XK_a)
		return (translate_right(fdf));
	else if (keycode == XK_s)
		return (translate_up(fdf));
	else if (keycode == XK_w)
		return (translate_down(fdf));
	return (0);
}
