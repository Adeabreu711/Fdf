/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivec_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:10:41 by alex              #+#    #+#             */
/*   Updated: 2025/04/16 17:25:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_ivec3	ft_ivec3_op(t_ivec3 v3_1, t_ivec3 v3_2, int(*op)(int, int))
{
	t_ivec3	new_v3;

	new_v3.x = op(v3_1.x, v3_2.x);
	new_v3.y = op(v3_1.y, v3_2.y);
	new_v3.z = op(v3_1.z, v3_2.z);
	return (new_v3);
}

t_ivec2	ft_ivec2_op(t_ivec2 v2_1, t_ivec2 v2_2, int(*op)(int, int))
{
	t_ivec2	new_v2;

	new_v2.x = op(v2_1.x, v2_2.x);
	new_v2.y = op(v2_1.y, v2_2.y);
	return (new_v2);
}
