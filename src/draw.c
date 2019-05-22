/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 17:56:44 by efrank         #+#    #+#                */
/*   Updated: 2019/05/22 14:56:50 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_pixel(t_mlx mlx, int x, int y, t_color color)
{
	int i;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = x * (mlx.bits_per_pixel / 8) + (y * mlx.line_size);
		mlx.pixel_addr[i] = color.blue;
		i++;
		mlx.pixel_addr[i] = color.green;
		i++;
		mlx.pixel_addr[i] = color.red;
	}
}

void		*draw_thread(void *data)
{
	t_mlx	*mlx;
	int		x;

	x = 0;
	mlx = (t_mlx *)data;
	while (mlx->start_y < mlx->end_y)
	{
		if (mlx->type == MANDEL)
			draw_pixel(*mlx, x, mlx->start_y, mandelbrot(mlx, x, mlx->start_y));
		else if (mlx->type == JULIA)
			draw_pixel(*mlx, x, mlx->start_y, julia(mlx, x, mlx->start_y));
		else if (mlx->type == SHIP)
			draw_pixel(*mlx, x, mlx->start_y, ship(mlx, x, mlx->start_y));
		else if (mlx->type == FRACLOL)
			draw_pixel(*mlx, x, mlx->start_y, fraclol(mlx, x, mlx->start_y));
		x++;
		if (x == WIDTH)
		{
			x = 0;
			mlx->start_y++;
		}
	}
	return (NULL);
}

int			draw_image(t_mlx *mlx)
{
	int			i;
	char		*fps;
	t_mlx		mlx_list[THREADS];
	pthread_t	thread_id[THREADS];

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy(&mlx_list[i], mlx, sizeof(t_mlx));
		mlx_list[i].start_y = (HEIGHT / THREADS) * i;
		mlx_list[i].end_y = (HEIGHT / THREADS) * (i + 1);
		pthread_create(&thread_id[i], NULL, &draw_thread, &mlx_list[i]);
		i++;
	}
	while (i >= 0)
	{
		i--;
		pthread_join(thread_id[i], NULL);
	}
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image, 0, 0);
	fps = ft_itoa(frames());
	mlx_string_put(mlx->init, mlx->window, 10, 10, 0xaaaaaa, fps);
	free(fps);
	return (1);
}
