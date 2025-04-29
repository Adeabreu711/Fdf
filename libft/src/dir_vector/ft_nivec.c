/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nivec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:31:27 by alex              #+#    #+#             */
/*   Updated: 2025/04/29 00:44:38 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

//return a new int vector3.
t_ivec3	ft_nivec3(int x, int y, int z)
{
	return ((t_ivec3){x, y, z});
}

//return a new int vector2.
t_ivec2	ft_nivec2(int x, int y)
{
	return ((t_ivec2){x, y});
}
