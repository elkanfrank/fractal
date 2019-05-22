/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 15:05:41 by efrank         #+#    #+#                */
/*   Updated: 2019/05/22 14:26:46 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage_and_exit(void)
{
	ft_putstr_fd("Usage: \n./fractal mandelbrot\n\
./fractal julia\n./fractal ship\n./fractal fraclol\n", 2);
	exit(1);
}

void		check_arguments(int argc, char **argv, t_mlx *mlx)
{
	if (argc > 2)
		print_usage_and_exit();
	if (argc == 2 && ft_strcmp(argv[1], "julia")
	&& ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "ship")
	&& ft_strcmp(argv[1], "fraclol"))
		print_usage_and_exit();
	else if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "mandelbrot"))
			mlx->type = MANDEL;
		else if (!ft_strcmp(argv[1], "julia"))
			mlx->type = JULIA;
		else if (!ft_strcmp(argv[1], "ship"))
			mlx->type = SHIP;
		else if (!ft_strcmp(argv[1], "fraclol"))
			mlx->type = FRACLOL;
	}
	else
		print_usage_and_exit();
}
