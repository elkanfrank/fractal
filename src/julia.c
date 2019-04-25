/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 13:54:47 by efrank         #+#    #+#                */
/*   Updated: 2019/04/25 14:48:21 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_values(t_fractal *fractal, int x, int y, t_mlx mlx)
{
	double zoom_offset;

	fractal->a = ft_map((double)x, 0, (double)WIDTH, -2.5, 1);
	fractal->b = ft_map((double)y, 0, (double)HEIGHT, -1, 1);
	fractal->a *= mlx.zoom;
	fractal->b *= mlx.zoom;
	if (mlx.zoomToggle)
	{
		fractal->a += ft_map(mlx.xPos, 0, (double)WIDTH, -2, 2);
		fractal->b += ft_map(mlx.yPos, 0, (double)HEIGHT, -2, 2);
	}
	fractal->ca = fractal->a;
	fractal->cb = fractal->b;
}


t_color		julia(t_mlx mlx, int x, int y)
{
	int			n;
	int			brightness;
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
		if (fabsl(fractal.a + fractal.b) > 6)
			break ;
		n++;
	}
	if (n == MAX_ITER)
		return (max_color());
	return (set_color(n));
}
