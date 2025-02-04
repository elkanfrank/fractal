/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:49:18 by efrank         #+#    #+#                */
/*   Updated: 2019/05/22 14:54:38 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	set_color(double n, int max)
{
	t_color	color;
	double	range[2];

	range[0] = 0;
	range[1] = max;
	if (n < max / 3)
	{
		color.red = ft_map(n, range, 0x10, 0x23);
		color.green = ft_map(n, range, 0x10, 0x80);
		color.blue = ft_map(n, range, 0x10, 0xF4);
	}
	else if (n < max / 2)
	{
		color.red = ft_map(n, range, 0x10, 0x99);
		color.green = ft_map(n, range, 0x10, 0xA4);
		color.blue = ft_map(n, range, 0x10, 0xF4);
	}
	else
	{
		color.red = ft_map(n, range, 0x10, 0xF2);
		color.green = ft_map(n, range, 0x10, 0xFF);
		color.blue = ft_map(n, range, 0x10, 0xE3);
	}
	return (color);
}

t_color	max_color(void)
{
	t_color color;

	color.red = 0x10;
	color.green = 0x10;
	color.blue = 0x10;
	return (color);
}
