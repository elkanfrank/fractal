/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 15:29:16 by efrank         #+#    #+#                */
/*   Updated: 2019/05/20 18:30:07 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: ship fractal
// TODO: better zoom

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
	&& ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "ship"))
	{
		ft_putstr_fd("Invalid argument\n", 2);
		exit(1);
	}
	else if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "mandelbrot"))
			mlx->type = 0;
		else if (!ft_strcmp(argv[1], "julia"))
			mlx->type = 1;
		else if (!ft_strcmp(argv[1], "ship"))
			mlx->type = 2;
	}
	else
		mlx->type = 0;
}

int		main(int argc, char **argv)
{
	t_mlx		mlx;
	pthread_t	thread_id;

	// pthread_create(&thread_id, NULL, &draw_image, &mlx);
	mlx = init();
	check_arguments(argc, argv, &mlx);
	// printf("%s\n", mlx.type);
	mlx_hook(mlx.window, 2, 1L << 2, &get_key, &mlx);
	mlx_hook(mlx.window, 4, 1L << 4, &mouse_press, &mlx);
	mlx_hook(mlx.window, 6, 1L << 6, &mouse_move, &mlx);
	mlx_loop_hook(mlx.init, draw_image, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
