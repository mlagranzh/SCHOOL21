#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include "Libft/libft.h"

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	k;
	t_complex	z;
	t_complex	c;
	char		*fract_ol;
	double		zoom;
	int			height;
	int			width;
	int			x_bias;
	int			y_bias;
	int			color;
}				t_vars;

typedef struct s_image
{
	int		color;
	int		pixel;
	char	*buffer;
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		color1;
}				t_image;

t_complex	init_complex(double re, double im);
int			mouse_press_hook(int button, int x, int y, t_vars *vars);
int			key_press(int keycode, t_vars *vars);
void		init_vars(t_vars *vars);
void		update_buffer(t_image *img, int i, int x, int y);

void		draw_julia(t_vars	*vars, t_image	*img);
void		julia(t_vars *vars);
int			julia_motion(int x, int y, t_vars *vars);

void		mandelbrot(t_vars *vars);
void		draw_mandelbrot(t_vars *vars, t_image *img);

void		mandelbar(t_vars *vars);
void		draw_mandelbar(t_vars *vars, t_image *img);

#endif
