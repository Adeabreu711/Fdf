/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_rotation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:49:04 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/02 02:24:14 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/input.h"

// Rotate view upwards to the right (increment x rotation)
int	rotate_top_right(t_fdf *fdf)
{
	fdf->cam.ctrl.rotation.x += 0.1f;
	rotate_projection(fdf);
	return (1);
}

// Rotate view downwards to the left (decrement x rotation)
int	rotate_bot_left(t_fdf *fdf)
{
	fdf->cam.ctrl.rotation.x -= 0.1f;
	rotate_projection(fdf);
	return (1);
}

// Rotate view downwards to the right (increment y rotation)
int	rotate_bot_right(t_fdf *fdf)
{
	fdf->cam.ctrl.rotation.y += 0.1f;
	rotate_projection(fdf);
	return (1);
}

// Rotate view upwards to the left (decrement y rotation)
int	rotate_top_left(t_fdf *fdf)
{
	fdf->cam.ctrl.rotation.y -= 0.1f;
	rotate_projection(fdf);
	return (1);
}
