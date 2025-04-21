/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:18:53 by alex              #+#    #+#             */
/*   Updated: 2025/04/21 22:35:04 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

#define W_HEIGHT 540
#define W_WIDTH 960

#include "../minilibx-linux/mlx_int.h"
#include "../minilibx-linux/mlx.h"
#include "../libft/includes/vector.h"

typedef struct s_point2
{
	t_ivec2	v2;
	int		color;
}	t_point2;

typedef struct s_point3
{
	t_ivec3	v3;
	int		color;
}	t_point3;

typedef struct	s_imgd {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_imgd;

typedef struct	s_mlxinfo
{
	void	*mlx;
	void	*window;
	t_ivec2	w_dim;
	t_imgd	img;
}	t_mlxinfo;

void		put_pixel(t_imgd *data, int x, int y, int color);
void		draw_line(t_imgd *img, t_point2 p1, t_point2 p2);

int			free_mlx(t_mlxinfo *mlx, char *err_msg);
int			mlx_setup_img(t_mlxinfo *mlx);
void		put_img_to_window(t_mlxinfo *mlx, int x, int y);

#endif
