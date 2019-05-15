/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   control.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 17:57:26 by efrank         #+#    #+#                */
/*   Updated: 2019/05/15 15:38:33 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_key(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(1);
	if (key == 123)
		mlx->xMove -= 10;
	if (key == 124)
		mlx->xMove += 10;
	if (key == 125)
		mlx->yMove += 10;
	if (key == 126)
		mlx->yMove -= 10;
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	mlx->xPos = x;
	mlx->yPos = y;
	if (button == 5) // ZOOM OUT
	{
		mlx->xMove -= (mlx->zoom_add / 100) * WIDTH;
		mlx->zoom += 0.05 * mlx->zoom;
		mlx->zoom_add--;
	}
	else if (button == 4) // ZOOM IN
	{
		mlx->xMove += (mlx->zoom_add / 100) * WIDTH;
		mlx->zoom -= 0.05 * mlx->zoom;
		mlx->zoom_add ++;
	}
	return (0);
}
