/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fps.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 13:51:13 by efrank         #+#    #+#                */
/*   Updated: 2019/05/22 14:25:34 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

static int	seconds(void)
{
	time_t		now;
	struct tm	*tijd;

	now = time(0);
	tijd = localtime(&now);
	return (tijd->tm_sec);
}

int			frames(void)
{
	static int	frames;
	static int	prev_sec;
	static int	fps;
	int			cur_sec;

	frames++;
	cur_sec = seconds();
	if (cur_sec != prev_sec)
	{
		prev_sec = cur_sec;
		fps = frames;
		frames = 0;
		return (fps);
	}
	return (fps);
}
