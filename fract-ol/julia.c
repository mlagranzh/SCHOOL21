#include "fractol.h"

void	update_buffer(t_image *img, int i, int x, int y)
{
	double	t;
	int		red;	
	int		green;
	int		blue;

	t = (double)i / 50.0;
	red = (int)((t) * 255 - img -> color1);
	green = (int)((t * t + 2 * t) * 255 + img -> color1);
	blue = (int)((t * t * t) * 255 - img -> color1);
	img -> color = 0 << 24 | red << 16 | green << 8 | blue;
	img -> pixel = (y * img -> line_bytes) + (x * 4);
	img -> buffer[img -> pixel + 1] = (img -> color >> 8) & 0xFF;
	img -> buffer[img -> pixel + 2] = (img -> color >> 16) & 0xFF;
	img -> buffer[img -> pixel + 3] = (img -> color >> 24);
}

void	draw_julia(t_vars *vars, t_image *img)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	img -> color1 = vars -> color;
	while ((++y) < vars -> height)
	{
		vars -> c.im = vars -> max.im - y * vars -> factor.im;
		x = 0;
		while ((++x) < vars -> width)
		{
			vars -> c.re = vars -> min.re + x * vars -> factor.re;
			vars -> z = init_complex(vars -> c.re, vars -> c.im);
			i = 0;
			while ((i++) < 50 && sqrt(pow(vars -> z.im, 2) + \
					vars -> z.re * vars -> z.re) < 2)
				vars -> z = init_complex(pow(vars -> z.re, 2) - \
				pow(vars -> z.im, 2) + vars->k.re, 2.0 * \
				vars -> z.re * vars -> z.im + vars->k.im);
			if (sqrt(vars -> z.im * vars -> z.im + \
				vars -> z.re * vars -> z.re) >= 2.0)
				update_buffer(img, i, x, y);
		}
	}
}

void	julia(t_vars *vars)
{
	t_image	img;

	mlx_clear_window(vars -> mlx, vars -> win);
	vars -> fract_ol = "julia";
	vars -> min.re += vars -> zoom;
	vars -> min.im += vars -> zoom;
	vars -> max.re -= vars -> zoom;
	vars -> max.im -= vars -> zoom;
	vars -> factor = init_complex((vars -> max.re - vars -> min.re) / \
	(vars -> width - 1), (vars -> max.im - vars -> min.im) / \
	(vars -> height - 1));
	img.image = mlx_new_image(vars -> mlx, vars -> height, vars -> width);
	img.buffer = mlx_get_data_addr(img.image, &(img.pixel_bits), \
									&(img.line_bytes), &(img.endian));
	draw_julia(vars, &img);
	mlx_put_image_to_window(vars -> mlx, vars -> win, img.image, \
							vars -> x_bias, vars -> y_bias);
	mlx_destroy_image(vars -> mlx, img.image);
}

int	julia_motion(int x, int y, t_vars *vars)
{
	vars -> k = init_complex(4 * ((double)x / vars -> width - 0.5),
			4 * ((double)(vars -> height - y) / vars -> height - 0.5));
	julia(vars);
	vars -> zoom = 0;
	return (0);
}
