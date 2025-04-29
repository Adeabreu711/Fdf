/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:34:05 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/29 21:04:07 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_vert_info(t_map	*map, t_ui *ui)
{
	ui->vrtcs = ft_strjoin("Vertices  : ", ft_itoa(map->size));
	ui->edgs = ft_strjoin("Edges     : ", ft_itoa(map->size));
	ui->fcs = ft_strjoin("Faces     : ", ft_itoa(map->size / 2));
	ui->tris = ft_strjoin("Triangles : ", ft_itoa(map->size / 2 * 2));
	printf("verts : %s\n edges : %s\n faces : %s\ntries : %s\n",
		ui->vrtcs, ui->edgs, ui->fcs, ui->tris);
}

void	init_ui(t_cam *cam, t_map *map, t_rdr *rdr, char *fd_name)
{
	t_ui	ui;

	set_vert_info(map, &ui);
	(void)cam;
	(void)rdr;
	(void)fd_name;
}
