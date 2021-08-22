#include "fractol.h"

void	mandelbrot(t_vars *vars)
{
	t_image	img;

	mlx_clear_window(vars -> mlx, vars -> win);
	vars -> min.re += vars -> zoom;
	vars -> min.im += vars -> zoom;
	vars -> max.re -= vars -> zoom;
	vars -> max.im -= vars -> zoom;
	vars -> factor = init_complex((vars -> max.re - vars -> min.re) / (vars -> width - 1), \
					(vars -> max.im - vars -> min.im) / (vars -> height - 1));
	img.image = mlx_new_image(vars -> mlx, vars -> height, vars -> width);
	img.buffer = mlx_get_data_addr(img.image, &(img.pixel_bits), \
									&(img.line_bytes), &(img.endian));
	draw_mandelbrot(vars, &img);
	mlx_put_image_to_window(vars -> mlx, vars -> win, img.image, 0, 0);
	mlx_destroy_image(vars -> mlx, img.image);
}

void	draw_mandelbrot(t_vars *vars, t_image *img)
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
			while ((i++) < 50 && sqrt(pow(vars -> z.im, 2.0) + \
					vars -> z.re * vars -> z.re) < 2.0)
				vars -> z = init_complex(pow(vars -> z.re, 2.0) - pow(vars -> z.im, 2.0) + vars->c.re, \
								2.0 * vars -> z.re * vars -> z.im + vars->c.im);
			if (sqrt(vars -> z.im * vars -> z.im + \
				vars -> z.re * vars -> z.re) >= 2.0)
				update_buffer(img, i, x, y);
		}
	}
}
