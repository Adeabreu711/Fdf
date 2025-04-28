/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_show_tri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:00:22 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/28 13:07:30 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

int	key_show_tri(int keycode, t_fdf *fdf)
{
	if (keycode == XK_t)
	{
		fdf->cam.show_tri = !fdf->cam.show_tri;
		refresh_projection(&fdf->mlx, fdf->map, &fdf->cam, fdf->rdr);
	}
	return (1);
}
