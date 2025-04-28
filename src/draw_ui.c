/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:19:39 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/28 17:10:06 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	get_window_sf(void)
{
	t_fvec2	scale_f;

	scale_f.x = (float)(W_WIDTH / 960);
	scale_f.y = (float)(W_HEIGHT / 540);

	if (scale_f.x < scale_f.y)
		return (scale_f.x);
	return (scale_f.y);
}

void draw_ui_rect(t_imgd *img, t_ivec2 dim, float w_sf, t_ivec2 dsp)
{
	t_ivec2	v2[2];

	dim = ft_ivec2_op(dim, ft_nivec2(w_sf, w_sf), ft_mult);
	v2[0] = ft_nivec2((W_WIDTH - dim.x) / 2, (W_HEIGHT - dim.y) / 2);
	v2[1] = ft_nivec2((W_WIDTH + dim.x) / 2, (W_HEIGHT + dim.y) / 2);
	draw_rect(img, v2, 1, dsp);
}
