/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 15:29:16 by efrank         #+#    #+#                */
/*   Updated: 2019/05/21 15:11:45 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: better zoom
// TODO: Change ft_map (too many arguments)
// TODO: Leaks + Norm

// BONUS
// 	Colors
//	Move around
//	x
// 	x
//	x

int		main(int argc, char **argv)
{
	t_mlx		mlx;

	mlx = init();
	check_arguments(argc, argv, &mlx);
	mlx_hook(mlx.window, 2, 1L << 2, &get_key, &mlx);
	mlx_hook(mlx.window, 4, 1L << 4, &mouse_press, &mlx);
	mlx_hook(mlx.window, 6, 1L << 6, &mouse_move, &mlx);
	mlx_loop_hook(mlx.init, draw_image, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
