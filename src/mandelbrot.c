/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:13:36 by efrank         #+#    #+#                */
/*   Updated: 2019/05/15 15:11:16 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_values(t_fractal *fractal, int x, int y, t_mlx mlx)
{
	double zoom_offset;

	fractal->a = ft_map((double)x + mlx.xMove, 0, (double)WIDTH, -2, 2);
	fractal->b = ft_map((double)y + mlx.yMove, 0, (double)HEIGHT, -2, 2);
	fractal->a *= mlx.zoom;
	fractal->b *= mlx.zoom;
	fractal->ca = fractal->a;
	fractal->cb = fractal->b;
}

t_color			mandelbrot(t_mlx mlx, int x, int y)
{
	double		n;
	int			brightness;
	t_fractal	fractal;

	set_values(&fractal, x, y, mlx);
	n = 0;
	while (n < MAX_ITER)
	{
		fractal.a_new = (fractal.a * fractal.a) - (fractal.b * fractal.b);
		fractal.b = 2 * fractal.a * fractal.b + fractal.cb;
		fractal.a = fractal.a_new + fractal.ca;
		if (fabsl(fractal.a + fractal.b) > 16)
			break ;
		n++;
	}
	n = n - log2(log2(fabs(fractal.a * fractal.a + fractal.b * fractal.b))) + 3;
	if (n == MAX_ITER)
		return (max_color());
	return (set_color(n));
}
