/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:55:09 by alex              #+#    #+#             */
/*   Updated: 2025/04/15 18:57:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define SB_SIZE 128

# include "libft.h"

typedef struct s_ivec3
{
	int		x;
	int		y;
	int		z;
}	t_ivec3;

typedef struct s_ivec2
{
	int		x;
	int		y;
}	t_ivec2;

#endif
