/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nivec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:31:27 by alex              #+#    #+#             */
/*   Updated: 2025/04/16 17:39:05 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_ivec3 ft_nivec3(int x, int y, int z)
{
	t_ivec3	new_v3;

	new_v3.x = x;
	new_v3.y = y;
	new_v3.z = z;
	return (new_v3);
}

t_ivec2 ft_nivec2(int x, int y)
{
	t_ivec2	new_v2;

	new_v2.x = x;
	new_v2.y = y;
	return (new_v2);
}
