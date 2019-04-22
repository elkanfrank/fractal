/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:13:36 by efrank         #+#    #+#                */
/*   Updated: 2019/04/22 16:21:38 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void set_values(t_fractal *fractal, int x, int y)
{
	fractal->a = ft_map((double)x, 0, (double)WIDTH, -2, 2);
	fractal->b = ft_map((double)y, 0, (double)HEIGHT, -2, 2);
	fractal->ca = fractal->a;
	fractal->cb = fractal->b;
}

t_color		mandelbrot(int x, int y)
{
	int			n;
	int			brightness;
	t_fractal	fractal;

	set_values(&fractal, x, y);
	n = 0;
	while (n < 100)
	{
		fractal.a_new = (fractal.a * fractal.a) - (fractal.b * fractal.b);
		fractal.b_new = 2 * fractal.a * fractal.b;
		fractal.a = fractal.a_new + fractal.ca;
		fractal.b = fractal.b_new + fractal.cb;
		if (fabs(fractal.a + fractal.b) > MAX_ITER)
			break ;
		n++;
	}
	brightness = ft_map((double)n, 0, 100, 0, 255);
	return (set_color(brightness, brightness, brightness));
}
