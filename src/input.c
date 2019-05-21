/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 15:05:41 by efrank         #+#    #+#                */
/*   Updated: 2019/05/21 15:15:15 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage_and_exit(void)
{
	ft_putstr_fd("Usage: \n./fractal mandelbrot\n\
./fractal julia\n./fractal ship\n", 2);
	exit(1);
}

void		check_arguments(int argc, char **argv, t_mlx *mlx)
{
	if (argc > 2)
		print_usage_and_exit();
	if (argc == 2 && ft_strcmp(argv[1], "julia")
	&& ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "ship"))
		print_usage_and_exit();
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
		print_usage_and_exit();
}
