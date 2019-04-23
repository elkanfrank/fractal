/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   control.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 17:57:26 by efrank         #+#    #+#                */
/*   Updated: 2019/04/23 12:44:11 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_key(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(1);
	if (key == 13)
		mlx->zoom += 0.05 * mlx->zoom;
	else if (key == 1)
		mlx->zoom -= 0.05 * mlx->zoom;
	return (0);
}
