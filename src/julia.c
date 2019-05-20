/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 13:54:47 by efrank         #+#    #+#                */
/*   Updated: 2019/05/20 17:57:04 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_values(t_fractal *fractal, int x, int y, t_mlx mlx)
{
	double zoom_offset;

	fractal->a = ft_map((double)x, 0, (double)WIDTH, -1, 1);
	fractal->b = ft_map((double)y, 0, (double)HEIGHT, -1, 1);
	fractal->a *= mlx.zoom;
	fractal->b *= mlx.zoom;
	fractal->ca = fractal->a;
	fractal->cb = fractal->b;
}


t_color		julia(t_mlx mlx, int x, int y)
{
	double		n;
	t_fractal	fractal;

	set_values(&fractal, x, y, mlx);
	n = 0;
	while (n < MAX_ITER)
	{
		fractal.a_new = (fractal.a * fractal.a) - (fractal.b * fractal.b);
		fractal.b = 2 * fractal.a * fractal.b +
		ft_map((double)mlx.yPos, 0, (double)HEIGHT, -2, 2);
		fractal.a = fractal.a_new +
		ft_map((double)mlx.xPos, 0, (double)WIDTH, -2, 2);
		if (fabs(fractal.a + fractal.b) > 6)
			break ;
		n++;
	}
	if (n == MAX_ITER)
		return (max_color());
	n = n - log2(log2(fabs(fractal.a * fractal.a + fractal.b * fractal.b))) + 3;
	return (set_color(n));
}
