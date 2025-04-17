/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:55:09 by alex              #+#    #+#             */
/*   Updated: 2025/04/16 17:38:59 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

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


//Functions

t_ivec3	ft_nivec3(int x, int y, int z);
t_ivec2	ft_nivec2(int x, int y);
t_ivec3	ft_ivec3_op(t_ivec3 v3_1, t_ivec3 v3_2, int(*op)(int, int));
t_ivec2	ft_ivec2_op(t_ivec2 v2_1, t_ivec2 v2_2, int(*op)(int, int));

//Operations

int	ft_mod(int nb1, int nb2);
int	ft_mult(int nb1, int nb2);
int	ft_div(int nb1, int nb2);
int	ft_sum(int nb1, int nb2);
int	ft_sub(int nb1, int nb2);

#endif
