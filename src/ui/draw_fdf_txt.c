/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:19:18 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 16:28:59 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void draw_text(t_mlxinfo *mlx, char *str)
{
	mlx_string_put(mlx->mlx, mlx->window, 215, 74, 0xFFFFFF, str);
}

void	draw_fdf_txt(t_mlxinfo *mlx, char *str)
{
	static char	*fd_nm = NULL;

	if (!fd_nm && !str)
		fd_nm = str;
	draw_text(mlx, fd_nm);
}
