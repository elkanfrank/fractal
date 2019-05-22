/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 15:30:06 by efrank         #+#    #+#                */
/*   Updated: 2019/05/22 15:00:10 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

# define WIDTH 1080
# define HEIGHT 960
# define THREADS 15
# define MAX_COLOR 0x0F7173
# define MANDEL 0
# define JULIA 1
# define SHIP 2
# define FRACLOL 3

typedef unsigned char	t_byte;

typedef struct	s_color {
	t_byte		red;
	t_byte		green;
	t_byte		blue;
}				t_color;

typedef struct	s_range {
	double		start;
	double		end;
}				t_range;

typedef struct	s_mlx {
	int			type;
	int			iterations;
	int			line_size;
	int			endian;
	int			bits_per_pixel;
	void		*init;
	void		*window;
	void		*image;
	double		zoom;
	int			zoom_add;
	char		*pixel_addr;
	int			start_y;
	int			end_y;
	int			x_pos;
	int			y_pos;
	double		x_move;
	double		y_move;
}				t_mlx;

typedef struct	s_fractal {
	double		a;
	double		b;
	double		a_new;
	double		b_new;
	double		ca;
	double		cb;
	double		zoom;
}				t_fractal;

t_mlx			init(void);
t_color			mandelbrot(t_mlx *mlx, int x, int y);
t_color			ship(t_mlx *mlx, int x, int y);
t_color			julia(t_mlx *mlx, int x, int y);
t_color			fraclol(t_mlx *mlx, int x, int y);
t_color			set_color(double n, int max);
t_color			max_color(void);
int				get_key(int key, t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
int				mouse_move(int x, int y, t_mlx *mlx);
int				draw_image(t_mlx *mlx);
void			draw_pixel(t_mlx mlx, int x, int y, t_color color);
void			check_arguments(int argc, char **argv, t_mlx *mlx);
int				frames(void);

#endif
