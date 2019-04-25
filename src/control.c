/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   control.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 17:57:26 by efrank         #+#    #+#                */
/*   Updated: 2019/04/25 14:53:01 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_key(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(1);
	if (key == 126)
		mlx->yPos += 5;
	if (key == 125)
		mlx->yPos -= 5;
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	mlx->xPos = x;
	mlx->yPos = y;
	printf("xPos: %d yPos: %d\n", mlx->xPos, mlx->yPos);
	if (button == 5)
	{
		mlx->zoom += 0.10 * mlx->zoom;
		mlx->zoomToggle = true;
	}
	else if (button == 4)
	{
		mlx->zoom -= 0.10 * mlx->zoom;
		mlx->zoomToggle = true;
	}
	return (0);
}
