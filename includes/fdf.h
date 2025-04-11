/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:50 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/11 19:53:45 by alde-abr         ###   ########.fr       */
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

typedef struct	s_imgd {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_imgd;

void		my_mlx_pixel_put(t_imgd *data, int x, int y, int color);
void		draw_line(t_imgd *img, t_point p1, t_point p2);
t_point		*parsing_map(int fd);
char		*get_map(int fd);
int			get_map_size(char *map, int *out_line_size);


int			free_mlx(void *mlx, void *window, char *err_msg);
int			mlx_setup_img(void **mlx, void **window, t_imgd *img);

#endif
