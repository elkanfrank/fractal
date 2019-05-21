/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:13:36 by efrank         #+#    #+#                */
/*   Updated: 2019/05/21 17:03:36 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_values(t_fractal *fractal, int x, int y, t_mlx mlx)
{
	double range[2];

	range[0] = 0;
	range[1] = WIDTH;
	fractal->a = ft_map((double)x, range, -2, 2) * mlx.zoom; // + mlx.xMove
	range[1] = HEIGHT;
	fractal->b = ft_map((double)y, range, -2, 2) * mlx.zoom; // + mlx.yMove
	fractal->ca = fractal->a;
	fractal->cb = fractal->b;
}

t_color			mandelbrot(t_mlx mlx, int x, int y)
{
	double		n;
	t_fractal	fractal;

	set_values(&fractal, x, y, mlx);
	n = 0;
	while (n < MAX_ITER)
	{
		fractal.a_new = (fractal.a * fractal.a) - (fractal.b * fractal.b);
		fractal.b = 2 * fractal.a * fractal.b + fractal.cb;
		fractal.a = fractal.a_new + fractal.ca;
		if (fabs(fractal.a + fractal.b) > 6)
			break ;
		n++;
	}
	if (n == MAX_ITER)
		return (max_color());
	n = n - log2(log2(fabs(fractal.a * fractal.a + fractal.b * fractal.b))) + 3;
	return (set_color(n));
}
