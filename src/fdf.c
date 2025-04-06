/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:25:08 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/06 19:07:57 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define W_HEIGHT 540
#define W_WIDTH 960
#define MLX_ERROR "%serror :\e[0m mlx pointer is null\n"
#define WINDOW_ERROR "%serror :\e[0m window pointer is null\n"

int	free_mlx(void *mlx, void *window, char *err_msg)
{
	ft_fprintf(2, err_msg, RED);
	if (window)
		mlx_destroy_window(mlx, window);
	if (mlx)
	{
		mlx_destroy_display(mlx);
    	free(mlx);
	}
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*window;

    mlx = mlx_init();
	if (!mlx)
		return (ft_fprintf(2, MLX_ERROR, RED));
	window = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "fdf");
	if (!window)
		return (free_mlx(mlx, window, WINDOW_ERROR));
	while (1)
	;
	return (free_mlx(mlx, window, ""));
}
