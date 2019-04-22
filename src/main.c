/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 15:29:16 by efrank         #+#    #+#                */
/*   Updated: 2019/04/22 13:18:30 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(void)
{
	t_mlx mlx;

	mlx = init();
	mlx_hook(mlx.window, 2, 1L << 2, &get_key, &mlx);
	mlx_loop_hook(mlx.init, &draw_image, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
