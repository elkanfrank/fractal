/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 15:29:16 by efrank         #+#    #+#                */
/*   Updated: 2019/05/15 15:57:25 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: Fix weird color glow thing
// TODO: Multi threading
// TODO: last fractal

// BONUS
// 	Colors
//	Move around
//	x
// 	x
//	x


int		main(void)
{
	t_mlx mlx;
	pthread_t thread_id;

	mlx = init();
	mlx_hook(mlx.window, 2, 1L << 2, &get_key, &mlx);
	mlx_hook(mlx.window, 4, 1L << 2, &mouse_press, &mlx);
	pthread_create(&thread_id, NULL, draw_image, &mlx);
	mlx_loop_hook(mlx.init, &draw_image, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
