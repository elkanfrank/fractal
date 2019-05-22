/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   control.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 17:57:26 by efrank         #+#    #+#                */
/*   Updated: 2019/05/22 15:00:57 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_key(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(1);
	if (key == 123)
		mlx->x_move -= 0.05 * mlx->zoom;
	if (key == 124)
		mlx->x_move += 0.05 * mlx->zoom;
	if (key == 125)
		mlx->y_move += 0.05 * mlx->zoom;
	if (key == 126)
		mlx->y_move -= 0.05 * mlx->zoom;
	if (key == 27)
		mlx->iterations -= 5;
	if (key == 24)
		mlx->iterations += 5;
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5)
		mlx->zoom += 0.05 * mlx->zoom;
	else if (button == 4)
		mlx->zoom -= 0.05 * mlx->zoom;
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->x_pos = x;
	mlx->y_pos = y;
	return (0);
}
