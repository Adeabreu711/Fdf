/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:55:18 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/26 02:11:29 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

t_fvec3	rotate_x(t_fvec3 v3, float rota);
t_fvec3	rotate_y(t_fvec3 v3, float rota);
t_fvec3	rotate_z(t_fvec3 v3, float rota);

t_fvec3	rotate(t_fvec3 v3, float rota, char axis)
{
	if (axis == 'x')
		return (rotate_x(v3, rota));
	if (axis == 'y')
		return (rotate_y(v3, rota));
	if (axis == 'z')
		return (rotate_z(v3, rota));
	return (ft_nfvec3((float)v3.x, (float)v3.y, (float)v3.z));
}

t_fvec3	rotate_x(t_fvec3 v3, float rota)
{
	t_fvec3	result;
	t_fvec3	m_x;
	t_fvec3	m_y;
	t_fvec3	m_z;

	m_x = ft_nfvec3(1, 0, 0);
	m_y = ft_nfvec3(0, cosf(rota), -sinf(rota));
	m_z = ft_nfvec3(0, sinf(rota), cosf(rota));
	result.x = (float)(m_x.x * v3.x + m_x.y * v3.y + m_x.z * v3.z);
	result.y = (float)(m_y.x * v3.x + m_y.y * v3.y + m_y.z * v3.z);
	result.z = (float)(m_z.x * v3.x + m_z.y * v3.y + m_z.z * v3.z);
	return (result);
}

t_fvec3	rotate_y(t_fvec3 v3, float rota)
{
	t_fvec3	result;
	t_fvec3	m_x;
	t_fvec3	m_y;
	t_fvec3	m_z;

	m_x = ft_nfvec3(cosf(rota), 0, sinf(rota));
	m_y = ft_nfvec3(0, 1, 0);
	m_z = ft_nfvec3(-sinf(rota), 0, cosf(rota));
	result.x = (float)(m_x.x * v3.x + m_x.y * v3.y + m_x.z * v3.z);
	result.y = (float)(m_y.x * v3.x + m_y.y * v3.y + m_y.z * v3.z);
	result.z = (float)(m_z.x * v3.x + m_z.y * v3.y + m_z.z * v3.z);
	return (result);
}

t_fvec3	rotate_z(t_fvec3 v3, float rota)
{
	t_fvec3	result;
	t_fvec3	m_x;
	t_fvec3	m_y;
	t_fvec3	m_z;

	m_x = ft_nfvec3(cosf(rota), -sinf(rota), 0);
	m_y = ft_nfvec3(sinf(rota), cosf(rota), 0);
	m_z = ft_nfvec3(0, 0, 1);
	result.x = (float)(m_x.x * v3.x + m_x.y * v3.y + m_x.z * v3.z);
	result.y = (float)(m_y.x * v3.x + m_y.y * v3.y + m_y.z * v3.z);
	result.z = (float)(m_z.x * v3.x + m_z.y * v3.y + m_z.z * v3.z);
	return (result);
}
