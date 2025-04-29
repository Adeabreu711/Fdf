/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:07:18 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/28 22:11:08 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	assign_display(t_ivec2 w_dim, t_ivec2 size, t_ivec2 dsp[2])
{
	float	w_sf;

	w_sf = get_window_sf();
	size = ft_ivec2_op(size, ft_nivec2(w_sf, w_sf), ft_mult);
	dsp[0] = ft_nivec2((w_dim.x - size.x) / 2, (w_dim.y - size.y) / 2);
	dsp[1] = ft_nivec2((w_dim.x + size.x) / 2, (w_dim.y + size.y) / 2);
}
