/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:48:14 by alex              #+#    #+#             */
/*   Updated: 2025/05/03 15:07:34 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

static t_ivec2	project_sinus(t_ctrl cam, t_fvec3 v3);
static t_ivec2	project_flat(t_ctrl cam, t_fvec3 v3);
static t_ivec2	project_iso(t_ctrl cam, t_fvec3 v3);

// Set projection functions for different views.
void	init_projections(t_rdr *rdr)
{
	rdr->prj[0] = project_iso;
	rdr->prj[1] = project_sinus;
	rdr->prj[2] = project_flat;
}

// Isometric projection function.
static t_ivec2	project_iso(t_ctrl cam, t_fvec3 v3)
{
	t_ivec2		v2;
	float		angle;

	angle = 0.523599;
	v2.x = (int)((v3.x - v3.y) * cosf(angle) * cam.scale + cam.offset.x);
	v2.y = (int)((v3.x + v3.y) * sinf(angle) * cam.scale - v3.z
			* cam.scale / cam.height + cam.offset.y);
	return (v2);
}

// Sinusoidal projection function.
static t_ivec2	project_sinus(t_ctrl cam, t_fvec3 v3)
{
	t_ivec2	v2;
	float	dist;
	float	sine_factor;

	dist = sqrtf(v3.x * v3.x + v3.y * v3.y + v3.z * v3.z);
	sine_factor = sinf(dist * 0.5f) * 1.0f;
	v2.x = (int)((v3.x + sine_factor) * cam.scale + cam.offset.x);
	v2.y = (int)((v3.y + sine_factor) * cam.scale - v3.z * cam.scale
			/ cam.height + cam.offset.y);
	return (v2);
}

// Flat projection function.
static t_ivec2	project_flat(t_ctrl cam, t_fvec3 v3)
{
	t_ivec2	v2;

	v2.x = (int)(v3.x * cam.scale + cam.offset.x);
	v2.y = (int)(v3.y * cam.scale + cam.offset.y);
	return (v2);
}
