/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 15:29:16 by efrank         #+#    #+#                */
/*   Updated: 2019/05/16 16:24:27 by elkanfrank    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: Multi threading
// TODO: last fractal

// BONUS
// 	Colors
//	Move around
//	x
// 	x
//	x

void	check_arguments(int argc, char **argv, t_mlx *mlx)
{
	if (argc > 2)
	{
		ft_putstr_fd("Too many arguments", 2);
		exit(1);
	}
	if (argc > 1 && ft_strcmp(argv[1], "julia")
	&& ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "mandelflop"))
	{
		ft_putstr_fd("Invalid argument\n", 2);
		exit(1);
	}
	else if (argc > 1)
		mlx->type = argv[1];
	else
		mlx->type = "mandelbrot";
}

int		main(int argc, char **argv)
{
	t_mlx		mlx;
	pthread_t	thread_id;

	mlx = init();
	// pthread_create(&thread_id, NULL, &draw_image, &mlx);
	check_arguments(argc, argv, &mlx);
	printf("%s\n", mlx.type);
	mlx_hook(mlx.window, 2, 1L << 2, &get_key, &mlx);
	mlx_hook(mlx.window, 4, 1L << 2, &mouse_press, &mlx);
	mlx_loop_hook(mlx.init, &draw_image, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
