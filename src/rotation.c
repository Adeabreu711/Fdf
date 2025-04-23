/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:55:18 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/23 16:53:20 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void	ft_rotate_x(t_ivec3 v3, t_cam *cam, float rota)
{
	t_ivec3	result;
	t_ivec3	m_x;
	t_ivec3	m_y;
	t_ivec3	m_z;

	m_x = ft_nivec3(1, 0, 0);
	m_y = ft_nivec3(0, cosf(rota), -sinf(rota));
	m_z = ft_nivec3(0, sin(rota), cos(rota));
	result.x = m_x.x * v3.x + m_x.y * v3.y + m_x.z * v3.z;
	result.y = m_y.x * v3.x + m_y.y * v3.y + m_y.z * v3.z;
	result.z = m_z.x * v3.x + m_z.y * v3.y + m_z.z * v3.z;
	return (result);
}

void	ft_rotate_y(t_ivec3 v3, t_cam *cam, float rota)
{
	t_ivec3	result;
	t_ivec3	m_x;
	t_ivec3	m_y;
	t_ivec3	m_z;

	m_x = ft_nivec3(cosf(rota), 0, sinf(rota));
	m_y = ft_nivec3(0, 1, 0);
	m_y = ft_nivec3(-sinf(rota), 0, cos(rota));
	result.x = m_x.x * v3.x + m_x.y * v3.y + m_x.z * v3.z;
	result.y = m_y.x * v3.x + m_y.y * v3.y + m_y.z * v3.z;
	result.z = m_z.x * v3.x + m_z.y * v3.y + m_z.z * v3.z;
	return (result);
}

t_ivec3	ft_rotate_z(t_ivec3 v3, t_cam *cam, float rota)
{
	t_ivec3	result;
	t_ivec3	m_x;
	t_ivec3	m_y;
	t_ivec3	m_z;

	m_x = ft_nivec3(cosf(rota), -sinf(rota), 0);
	m_y = ft_nivec3(sinf(rota), cosf(rota), 0);
	m_z = ft_nivec3(0, 0, 1);
	result.x = m_x.x * v3.x + m_x.y * v3.y + m_x.z * v3.z;
	result.y = m_y.x * v3.x + m_y.y * v3.y + m_y.z * v3.z;
	result.z = m_z.x * v3.x + m_z.y * v3.y + m_z.z * v3.z;
	return (result);
}
