/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:50 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/03 15:15:13 by alde-abr         ###   ########.fr       */
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
	t_ui		ui;
	t_mlxinfo	mlx;
}	t_fdf;

//___________UI___________
//________________________

void		draw_ui_box(t_fdf *fdf);
void		draw_ui_txt(t_fdf *fdf);
float		get_window_sf(void);
int			free_ui(t_ui *ui);
void		nullset_ui(t_ui *ui);
t_ui		init_ui(t_cam *cam, t_map *map, t_rdr *rdr, char *fd_name);
void		refresh_ui_zoom(t_cam *cam, t_ui *ui);
void		refresh_ui_prj(t_cam *cam, t_ui *ui);

#endif
