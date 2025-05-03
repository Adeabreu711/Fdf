/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:34:05 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/03 14:53:24 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Join a string and an int, return the new allocated string
static char	*join_str_int(char *txt, int nb)
{
	char	*mrg;
	char	*tmp;

	tmp = ft_itoa(nb);
	mrg = ft_strjoin(txt, tmp);
	free(tmp);
	return (mrg);
}

// Update zoom percentage string in UI based on camera scale
void	refresh_ui_zoom(t_cam *cam, t_ui *ui)
{
	float	percent;
	char	*tmp;

	if (ui->zoom)
		free(ui->zoom);
	percent = ((cam->ctrl.scale - cam->stgs.lmt_scale.x)
			* 100 / (cam->stgs.lmt_scale.y - cam->stgs.lmt_scale.x));
	if (percent >= 100)
		percent = 100;
	tmp = join_str_int("Zoom  [", (int)percent);
	ui->zoom = ft_strjoin(tmp, "%]");
	free(tmp);
}

// Update projection name in UI based on current projection ID
void	refresh_ui_prj(t_cam *cam, t_ui *ui)
{
	if (ui->prj_nm)
		free(ui->prj_nm);
	if (cam->ctrl.prj_id == 0)
		ui->prj_nm = ft_strdup("Isometric");
	else if (cam->ctrl.prj_id == 1)
		ui->prj_nm = ft_strdup("Sinusoid");
	else if (cam->ctrl.prj_id == 2)
		ui->prj_nm = ft_strdup("Flat");
}

// Initialize the UI struct with map, camera, and file data
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
