/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:13:36 by efrank         #+#    #+#                */
/*   Updated: 2019/04/22 17:11:03 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_values(t_fractal *fractal, int x, int y)
{
	fractal->a = ft_map((double)x, 0, (double)WIDTH, -2, 2);
	fractal->b = ft_map((double)y, 0, (double)HEIGHT, -2, 2);
	fractal->ca = fractal->a;
	fractal->cb = fractal->b;
}

static t_color	set_color(int n)
{
	t_color color;

	color.red = ft_map((double)n, 0, MAX_ITER, 0x10, 0x0F);
	color.green = ft_map((double)n, 0, MAX_ITER, 0x10, 0x71);
	color.blue = ft_map((double)n, 0, MAX_ITER, 0x10, 0x73);
	return (color);
}

t_color			mandelbrot(int x, int y)
{
	int			n;
	int			brightness;
	t_fractal	fractal;

	set_values(&fractal, x, y);
	n = 0;
	while (n < MAX_ITER)
	{
		fractal.a_new = (fractal.a * fractal.a) - (fractal.b * fractal.b);
		fractal.b_new = 2 * fractal.a * fractal.b;
		fractal.a = fractal.a_new + fractal.ca;
		fractal.b = fractal.b_new + fractal.cb;
		if (fabs(fractal.a + fractal.b) > 100)
			break ;
		n++;
	}
	return (set_color(n));
}
