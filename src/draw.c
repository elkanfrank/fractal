/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 17:56:44 by efrank         #+#    #+#                */
/*   Updated: 2019/04/24 14:37:41 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(t_mlx mlx, int x, int y, t_color color)
{
	int i;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = x * (mlx.bits_per_pixel / 8) + (y * mlx.line_size);
		mlx.pixel_addr[i] = color.blue;
		mlx.pixel_addr[++i] = color.green;
		mlx.pixel_addr[++i] = color.red;
	}
}

int			draw_image(t_mlx *mlx)
{
	int y;
	int x;

	ft_bzero(mlx->pixel_addr, WIDTH * HEIGHT * (mlx->bits_per_pixel / 8));
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(*mlx, x, y, mandelbrot(*mlx, x, y));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image, 0, 0);
	return (1);
}
