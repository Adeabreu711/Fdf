/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:34:05 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/30 20:57:10 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*join_str_int(char *txt, int nb)
{
	char	*mrg;
	char	*tmp;

	tmp =	ft_itoa(nb);
	mrg = ft_strjoin(txt, tmp);
	free(tmp);
	return (mrg);
}
void	refresh_ui_zoom(t_cam *cam, t_ui *ui)
{
	float	percent;
	char	*tmp;

	if (ui->zoom)
		free(ui->zoom);
	percent = ((cam->ctrl.scale - cam->stgs.lmt_scale.x) * 100 /
			(cam->stgs.lmt_scale.y - cam->stgs.lmt_scale.x));
	if (percent >= 100)
		percent = 100;
	tmp = join_str_int("Zoom [", (int)percent);
	ui->zoom = ft_strjoin(tmp, "%]");
	free(tmp);
}

t_ui	init_ui(t_cam *cam, t_map *map, t_rdr *rdr, char *fd_name)
{
	t_ui	ui;

	nullset_ui(&ui);
	ui.fd_nm = ft_strrchr(fd_name, '/') + 1;
	ui.prj_nm = ft_strdup("Isometric");
	ui.vrtcs = join_str_int("Vertices   ", map->size);
	ui.edgs = join_str_int("Edges      ",
		map->size * 2 - (map->row_len + (map->size / map->row_len)));
	ui.fcs = join_str_int("Faces      ", map->size / 2);
	ui.tris = join_str_int("Triangles  ", map->size / 4);
	refresh_ui_zoom(cam, &ui);
	(void)rdr;
	return (ui);
}
