/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:32:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 02:16:47 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

// Increase height scaling if above lower limit
static int	reduce_height(t_fdf *fdf)
{
	if (fdf->cam.ctrl.height >= fdf->cam.stgs.lmt_height.y)
		return (1);
	fdf->cam.ctrl.height += 0.2f * fdf->cam.ctrl.height;
	refresh_projection(fdf);
	return (1);
}

// Decrease height scaling if below upper limit
static int	add_height(t_fdf *fdf)
{
	if (fdf->cam.ctrl.height <= fdf->cam.stgs.lmt_height.x)
		return (1);
	fdf->cam.ctrl.height -= 0.2f * fdf->cam.ctrl.height / 2;
	refresh_projection(fdf);
	return (1);
}

// Handle key inputs to increase or decrease height scaling
int	key_height(int keycode, t_fdf *fdf)
{
	if (keycode == XK_KP_Add)
		return (add_height(fdf));
	else if (keycode == XK_KP_Subtract)
		return (reduce_height(fdf));
	return (0);
}
