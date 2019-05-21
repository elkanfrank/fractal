/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   control.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 17:57:26 by efrank         #+#    #+#                */
/*   Updated: 2019/05/21 18:08:54 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_key(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(1);
	if (key == 123)
		mlx->xMove -= 0.2 * mlx->zoom;
	if (key == 124)
		mlx->xMove += 0.2 * mlx->zoom;
	if (key == 125)
		mlx->yMove += 0.2 * mlx->zoom;
	if (key == 126)
		mlx->yMove -= 0.2 * mlx->zoom;
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5) // ZOOM OUT
		mlx->zoom += 0.05 * mlx->zoom;
	else if (button == 4) // ZOOM IN
		mlx->zoom -= 0.05 * mlx->zoom;
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->xPos = x;
	mlx->yPos = y;
	return (0);
}