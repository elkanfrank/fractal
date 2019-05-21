/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:49:18 by efrank         #+#    #+#                */
/*   Updated: 2019/05/21 17:25:55 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	set_color(double n)
{
	t_color color;
	double range[2];

	range[0] = 0;
	range[1] = MAX_ITER;
	if (n < MAX_ITER / 3)
	{
		color.red = ft_map(n, range, 0x10, 0x23);
		color.green = ft_map(n, range, 0x10, 0x80);
		color.blue = ft_map(n, range, 0x10, 0xF4);
	}
	else if (n < MAX_ITER / 2)
	{
		color.red = ft_map(n, range, 0x23, 0x99);
		color.green = ft_map(n, range, 0x80, 0xF4);
		color.blue = ft_map(n, range, 0xF4, 0xB3);
	}
	else
	{
		color.red = ft_map(n, range, 0x99, 0xAB);
		color.green = ft_map(n, range, 0xF4, 0xFF);
		color.blue = ft_map(n, range, 0xB3, 0xE3);
	}
	return (color);
}

t_color max_color(void)
{
	t_color color;

	color.red = 0x10;
	color.green = 0x10;
	color.blue = 0x10;
	return (color);
}
