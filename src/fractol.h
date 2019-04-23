/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 15:30:06 by efrank         #+#    #+#                */
/*   Updated: 2019/04/23 12:42:13 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 1080
# define HEIGHT 960
# define MAX_ITER 100
# define MAX_COLOR 0x0F7173
# define MIN_COLOR 0xF05D5E

typedef unsigned char	t_byte;

typedef struct	s_color {
	t_byte		red;
	t_byte		green;
	t_byte		blue;
}				t_color;

typedef struct	s_mlx {
	int			line_size;
	int			endian;
	int			bits_per_pixel;
	void		*init;
	void		*window;
	void		*image;
	char		*pixel_addr;
	double		zoom;
}				t_mlx;

typedef struct 	s_fractal {
	double		a;
	double		b;
	double		a_new;
	double		b_new;
	double		ca;
	double		cb;
	double		zoom;
}				t_fractal;

t_mlx			init(void);
t_color			mandelbrot(t_mlx mlx, int x, int y);
int				get_key(int key, t_mlx *mlx);
int				draw_image(t_mlx *mlx);
void			draw_pixel(t_mlx mlx, int x, int y, t_color color);
