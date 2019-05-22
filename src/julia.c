/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 13:54:47 by efrank         #+#    #+#                */
/*   Updated: 2019/05/22 14:58:50 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_values(t_fractal *fractal, int x, int y, t_mlx *mlx)
{
	double range[2];

	range[0] = 0;
	range[1] = WIDTH;
	fractal->a = ft_map((double)x, range, -2, 2) * mlx->zoom + mlx->x_move;
	range[1] = HEIGHT;
	fractal->b = ft_map((double)y, range, -2, 2) * mlx->zoom + mlx->y_move;
	fractal->ca = fractal->a;
	fractal->cb = fractal->b;
}

t_color			julia(t_mlx *mlx, int x, int y)
{
	double		n;
	double		range[2];
	t_fractal	fractal;

	range[0] = 0;
	range[1] = HEIGHT;
	set_values(&fractal, x, y, mlx);
	n = 0;
	while (n < mlx->iterations)
	{
		fractal.a_new = (fractal.a * fractal.a) - (fractal.b * fractal.b);
		fractal.b = 2 * fractal.a * fractal.b +
		ft_map((double)mlx->y_pos, range, -2, 2);
		range[1] = WIDTH;
		fractal.a = fractal.a_new +
		ft_map((double)mlx->x_pos, range, -2, 2);
		if (fabs(fractal.a + fractal.b) > 6)
			break ;
		n++;
	}
	if (n == mlx->iterations)
		return (max_color());
	n = n - log2(log2(fabs(fractal.a * fractal.a + fractal.b * fractal.b))) + 3;
	return (set_color(n, mlx->iterations));
}
