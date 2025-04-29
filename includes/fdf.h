/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:50 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 19:31:07 by alde-abr         ###   ########.fr       */
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

typedef struct s_ui
{
	char	*fd_nm;
	char	*prj_nm;
	char	*vrtcs;
	char	*edgs;
	char	*fcs;
	char	*tris;
	char	*zoom;
}	t_ui;

typedef struct s_fdf
{
	t_cam		cam;
	t_map		map;
	t_rdr		rdr;
	t_mlxinfo	mlx;
}	t_fdf;

//UI

void		draw_fdf_box(t_mlxinfo *mlx);
void		draw_fdf_txt(t_fdf *fdf, char *str);
float		get_window_sf(void);

//___________DEBUG___________
//___________________________

void		debug_map(t_map map, int show_pts);
void		debug_cam(t_cam cam, t_map map, int show_pts);

#endif
