/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 15:29:16 by efrank         #+#    #+#                */
/*   Updated: 2019/04/25 16:04:46 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: Zoom follows mouse position but does not work properly yet for larger zooms
// TODO: Mouse position is not updated unless there is a click event
// TODO: Get more colors
// TODO: Julia set + optional fractal

int		main(void)
{
	t_mlx mlx;

	mlx = init();
	mlx_hook(mlx.window, 2, 1L << 2, &get_key, &mlx);
	mlx_hook(mlx.window, 4, 1L << 2, &mouse_press, &mlx);
	mlx_loop_hook(mlx.init, &draw_image, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
