/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:25:08 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/07 18:09:57 by alde-abr         ###   ########.fr       */
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
	t_imgd	img;


    mlx = mlx_init();
	if (!mlx)
		return (ft_fprintf(2, MLX_ERROR, RED));
	window = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "fdf");
	if (!window)
		return (free_mlx(mlx, window, WINDOW_ERROR));
	img.img = mlx_new_image(mlx, W_WIDTH ,W_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0xFFFFFF);

	int res = 16;
	for (int k = 0; k < res; k++) {
		int offx = 200;
		int offy = 200;
		int rad = 100;
		float angle = (float)k / (float)res * 6.28f;
		float angle2 = (float)((k + 1) % res) / (float)res * 6.28f;
		t_point p0 = {offx, offy};
		t_point p1 = {offx + rad * cos(angle), offy + rad * sin(angle)};
		t_point p2 = {offx + rad * cos(angle2), offy + rad * sin(angle2)};
		if (p0.x != p1.x)
			draw_line(&img, p0, p1);
		if (p1.x != p2.x)
			draw_line(&img, p1, p2);
	}

	// t_point p0 = {100, 100, 0, 0xFFFFFF};
	// t_point p1 = {200, 200, 0, 0xFFFFFF};
	// t_point p2 = {100, 400, 0, 0xFFFFFF};
	// draw_line(&img, p0, p1);
	// draw_line(&img, p2, p1);

	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
	return (free_mlx(mlx, window, ""));
}
