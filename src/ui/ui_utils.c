/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:54:47 by alde-abr          #+#    #+#             */
/*   Updated: 2025/05/03 14:53:57 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Reset all UI elements to NULL
void	nullset_ui(t_ui *ui)
{
	ui->vrtcs = NULL;
	ui->edgs = NULL;
	ui->fcs = NULL;
	ui->tris = NULL;
	ui->fd_nm = NULL;
	ui->prj_nm = NULL;
	ui->zoom = NULL;
}

// Free all allocated UI elements and reset to NULL
int	free_ui(t_ui *ui)
{
	if (ui->edgs)
		free(ui->edgs);
	if (ui->vrtcs)
		free(ui->vrtcs);
	if (ui->fcs)
		free(ui->fcs);
	if (ui->tris)
		free(ui->tris);
	if (ui->prj_nm)
		free(ui->prj_nm);
	if (ui->zoom)
		free(ui->zoom);
	nullset_ui(ui);
	return (1);
}
