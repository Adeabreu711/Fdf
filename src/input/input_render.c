/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:13:03 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/26 02:07:32 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

void	swap_projection(t_fdf *fdf, int id)
{
	fdf->cam.prj_id = id;
	reset_rotation(fdf->map, &fdf->cam);
	refresh_projection(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
}

int	key_render(int keycode, t_fdf *fdf)
{
	if (keycode == XK_F1)
		swap_projection(fdf, 0);
	else if (keycode == XK_F2)
		swap_projection(fdf, 1);
	else if (keycode == XK_F3)
		swap_projection(fdf, 2);
}
