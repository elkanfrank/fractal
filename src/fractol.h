/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 15:30:06 by efrank         #+#    #+#                */
/*   Updated: 2019/04/25 17:18:23 by efrank        ########   odam.nl         */
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
	int			zoomToggle;
	int			xPos;
	int			yPos;
}				t_mlx;

typedef struct	s_fractal {
	long double	a;
	long double	b;
	long double	a_new;
	long double	b_new;
	long double	ca;
	long double	cb;
	long double	zoom;
}				t_fractal;

t_mlx			init(void);
t_color			mandelbrot(t_mlx mlx, int x, int y);
t_color			julia(t_mlx mlx, int x, int y);
t_color			set_color(int n);
t_color			max_color(void);
int				get_key(int key, t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
int				draw_image(t_mlx *mlx);
void			draw_pixel(t_mlx mlx, int x, int y, t_color color);
