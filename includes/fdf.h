/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:50 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/14 19:58:25 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// #include <fcntl.h>

#include "../minilibx-linux/mlx_int.h"
#include "../minilibx-linux/mlx.h"

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_string_builder.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/color.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct	s_map
{
	int		size;
	int		row_len;
	t_point	*pts;
}	t_map;

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
	t_imgd	img;
}	t_mlxinfo;

void		put_pixel(t_imgd *data, int x, int y, int color);
void		draw_line(t_imgd *img, t_point p1, t_point p2);

void		scale_map(t_map *map, float scale);
int			display_points(t_imgd *img, t_map map);

int			parse_map(int fd, t_map *map);
t_point		*get_points(char *r_map, int map_size, int raw_len);

void		debug_points(t_point *points);

int			free_mlx(t_mlxinfo *mlx, char *err_msg);
int			mlx_setup_img(t_mlxinfo *mlx);
void		put_img_to_window(t_mlxinfo *mlx, int x, int y);

#endif
