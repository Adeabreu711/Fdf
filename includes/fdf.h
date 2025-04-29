/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:50 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 02:02:58 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "my_mlx.h"
# include "map.h"
# include "camera_.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_string_builder.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/color.h"
# include "../libft/includes/vector.h"

typedef struct s_fdf
{
	t_cam		cam;
	t_map		map;
	t_rdr		rdr;
	t_mlxinfo	mlx;
}	t_fdf;


//UI
void		draw_ui_rect(t_imgd *img, t_ivec2 *w_dim, t_ivec2 dim);
void		draw_text(t_mlxinfo *mlx, char *fd_nm);
float		get_window_sf(void);

//___________DEBUG___________
//___________________________

void		debug_map(t_map map, int show_pts);
void		debug_cam(t_cam cam, t_map map, int show_pts);

#endif
