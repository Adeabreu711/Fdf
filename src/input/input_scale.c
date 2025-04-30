/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:33:00 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/30 12:55:57 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	zoom_in(t_fdf *fdf)
{
	if (fdf->cam.ctrl.scale >= fdf->cam.stgs.lmt_scale.y)
		return (1);
	fdf->cam.ctrl.scale += 0.2f * fdf->cam.ctrl.scale / 2;
	refresh_projection(fdf);
	return (1);
}

int	zoom_out(t_fdf *fdf)
{
	if (fdf->cam.ctrl.scale <= fdf->cam.stgs.lmt_scale.x)
		return (1);
	fdf->cam.ctrl.scale -= 0.2f * fdf->cam.ctrl.scale / 2;
	refresh_projection(fdf);
	return (1);
}

int	button_scale(int button, t_fdf *fdf)
{
	if (button == 4)
		return (zoom_in(fdf));
	else if (button == 5)
		return (zoom_out(fdf));
	return (0);
}
