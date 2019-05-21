/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 14:58:28 by efrank         #+#    #+#                */
/*   Updated: 2019/05/21 17:02:04 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double        ft_map(double n, double *range, double y, double z)
{
    return ((n - range[0]) * (z - y) / (range[1] - range[0]) + y);
}
