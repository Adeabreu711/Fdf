/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:48:14 by alex              #+#    #+#             */
/*   Updated: 2025/04/17 02:50:04 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

t_ivec2	project_flat(t_ivec3 v3)
{
	t_ivec2 v2;

	v2.x = v3.x;
	v2.y = v3.y;
	return (v2);
}

t_ivec2	project_iso(t_cam cam, t_ivec3 v3)
{
	t_ivec2		v2;
	float		angle;

	angle = 0.523599;
	angle = M_PI_4;

	v2.x = (int)((v3.x - v3.y) * cosf(angle) * 24.0  + cam.offset.x + 325);
	v2.y = (int)((v3.x + v3.y) * sinf(angle) * 24.0 - v3.z * cam.scale / 15 + cam.offset.y + 0);

	return (v2);
}
