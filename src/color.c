/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:49:18 by efrank         #+#    #+#                */
/*   Updated: 2019/04/25 15:14:16 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	set_color(int n)
{
	t_color color;

	if (n < MAX_ITER / 3)
	{
		color.red = ft_map((double)n, 0, MAX_ITER, 0x10, 0x23);
		color.green = ft_map((double)n, 0, MAX_ITER, 0x10, 0x80);
		color.blue = ft_map((double)n, 0, MAX_ITER, 0x10, 0xF4);
	}
	else if (n < MAX_ITER / 2)
	{
		color.red = ft_map((double)n, 0, MAX_ITER, 0x10, 0x99);
		color.green = ft_map((double)n, 0, MAX_ITER, 0x10, 0xF4);
		color.blue = ft_map((double)n, 0, MAX_ITER, 0x10, 0xB3);
	}
	else
	{
		color.red = ft_map((double)n, 0, MAX_ITER, 0x10, 0xF0);
		color.green = ft_map((double)n, 0, MAX_ITER, 0x10, 0xF4);
		color.blue = ft_map((double)n, 0, MAX_ITER, 0x10, 0xD3);		
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
