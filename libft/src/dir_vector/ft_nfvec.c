/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nfvec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:31:16 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/24 15:55:51 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_fvec3 ft_nfvec3(float x, float y, float z)
{
	t_fvec3	new_v3;

	new_v3.x = x;
	new_v3.y = y;
	new_v3.z = z;
	return (new_v3);
}

t_fvec2 ft_nfvec2(float x, float y)
{
	t_fvec2	new_v2;

	new_v2.x = x;
	new_v2.y = y;
	return (new_v2);
}
