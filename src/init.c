/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 17:56:42 by efrank         #+#    #+#                */
/*   Updated: 2019/05/22 15:00:28 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	init(void)
{
	t_mlx mlx;

	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, WIDTH, HEIGHT, "fractol");
	mlx.image = mlx_new_image(mlx.init, WIDTH, HEIGHT);
	mlx.zoom = 1;
	mlx.iterations = 60;
	mlx.zoom_add = 1;
	mlx.x_pos = 0;
	mlx.y_pos = 0;
	mlx.pixel_addr = mlx_get_data_addr(mlx.image, &(mlx.bits_per_pixel),
	&(mlx.line_size), &(mlx.endian));
	return (mlx);
}
