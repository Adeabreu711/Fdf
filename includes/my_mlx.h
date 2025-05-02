/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:18:53 by alex              #+#    #+#             */
/*   Updated: 2025/05/01 17:17:54 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

# define W_HEIGHT 540
# define W_WIDTH 960

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/vector.h"

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

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_imgd
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_imgd;

typedef struct s_mlxinfo
{
	void	*mlx;
	void	*window;
	float	w_sf;
	t_ivec2	w_dim;
	t_imgd	img;
}	t_mlxinfo;

void		put_pixel(t_imgd *img, t_ivec2 v2, int color, t_ivec2 dsp[2]);
void		draw_line(t_imgd *img, t_point2 p1, t_point2 p2, t_ivec2 dsp[2]);
void		draw_rect(t_imgd *img, t_ivec2 crns[2], int width, t_ivec2 dsp[2]);
void		draw_frect(t_imgd *img, t_ivec2 crns[2], t_ivec2 dsp[2], int color);

int			lerp_color(int color1, int color2, float grad);
int			rgb_to_int(t_color c);
t_color		int_to_rgb(int color);

int			free_mlx(t_mlxinfo *mlx);
int			mlx_setup_img(t_mlxinfo *mlx);
void		put_img_to_window(t_mlxinfo *mlx, int x, int y);

float		get_window_sf(void);
void		refresh_img(t_mlxinfo *mlx);
void		img_init(t_imgd *img);

#endif
