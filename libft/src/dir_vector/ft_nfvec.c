/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nfvec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:31:16 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 00:44:21 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

//return a new float vector3.
t_fvec3	ft_nfvec3(float x, float y, float z)
{
	return ((t_fvec3){x, y, z});
}

//return a new float vector2.
t_fvec2	ft_nfvec2(float x, float y)
{
	return ((t_fvec2){x, y});
}
