/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_stgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:07:18 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/03 14:55:54 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Set display position and size based on window and scale factor
void	set_display(t_ivec2 w_dim, t_ivec2 size, t_ivec2 dsp[2])
{
	float	w_sf;

	w_sf = get_window_sf();
	size = ft_ivec2_op(size, ft_nivec2(w_sf, w_sf), ft_mult);
	dsp[0] = ft_nivec2((w_dim.x - size.x) / 2, (w_dim.y - size.y) / 2);
	dsp[1] = ft_nivec2((w_dim.x + size.x) / 2, (w_dim.y + size.y) / 2);
}

// Set height limits based on camera control settings
static void	set_height_limit(t_cam *cam)
{
	cam->stgs.lmt_height = ft_nfvec2(cam->ctrl.height, cam->ctrl.height);
	cam->stgs.lmt_height.x -= cam->ctrl.height * 0.5f;
	cam->stgs.lmt_height.y += cam->ctrl.height * 4.0f;
}

// Set scale limits based on camera control settings
static void	set_scale_limit(t_cam *cam)
{
	cam->stgs.lmt_scale = ft_nfvec2(cam->ctrl.scale, cam->ctrl.scale);
	cam->stgs.lmt_scale.x -= cam->ctrl.scale * 0.5f;
	cam->stgs.lmt_scale.y += cam->ctrl.scale * 6.0f;
}

// Set offset limits based on camera control settings
static void	set_offset_limit(t_cam *cam)
{
	cam->stgs.lmt_offset_x = ft_nivec2(cam->ctrl.offset.x, cam->ctrl.offset.x);
	cam->stgs.lmt_offset_y = ft_nivec2(cam->ctrl.offset.y, cam->ctrl.offset.y);
	cam->stgs.lmt_offset_x.x -= (float)cam->ctrl.offset.x * 0.5f;
	cam->stgs.lmt_offset_x.y += (float)cam->ctrl.offset.x * 0.5f;
	cam->stgs.lmt_offset_y.x -= (float)cam->ctrl.offset.y * 0.5f;
	cam->stgs.lmt_offset_y.y += (float)cam->ctrl.offset.y * 0.5f;
}

// Set all camera limits (height, scale, and offset)
void	set_limits(t_cam *cam)
{
	set_scale_limit(cam);
	set_offset_limit(cam);
	set_height_limit(cam);
}
