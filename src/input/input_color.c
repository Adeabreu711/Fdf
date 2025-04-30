/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:26:25 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/30 12:46:45 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

void	apply_color(t_fdf *fdf)
{
	if (fdf->cam.ctrl.color_id == 0)
		get_dflt_color(&fdf->map, &fdf->cam);
	else
		color_map(&fdf->map, &fdf->cam, fdf->rdr.c_grad[fdf->cam.ctrl.color_id - 1]);
	refresh_projection(fdf);
}

int	next_color(t_fdf *fdf)
{
	fdf->cam.ctrl.color_id++;
	if (fdf->cam.ctrl.color_id > COLOR_S)
		fdf->cam.ctrl.color_id = 0;
	apply_color(fdf);
	return (1);
}

int	previous_color(t_fdf *fdf)
{
	fdf->cam.ctrl.color_id--;
	if (fdf->cam.ctrl.color_id < 0)
		fdf->cam.ctrl.color_id = COLOR_S;
	apply_color(fdf);
	return (1);
}

int	key_color(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Up)
		return (next_color(fdf));
	else if (keycode == XK_Down)
		return (previous_color(fdf));
	return (0);
}
