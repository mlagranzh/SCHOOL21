#include "fractol.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		vars -> x_bias -= 1;
	if (keycode == 124)
		vars -> x_bias += 1;
	if (keycode == 125)
		vars -> y_bias += 1;
	if (keycode == 126)
		vars -> y_bias -= 1;
	if (keycode == 18)
		vars -> color = 5;
	if (keycode == 19)
		vars -> color = -10;
	if (keycode == 20)
		vars -> color = -100;
	if (!ft_strncmp(vars -> fract_ol, "mandelbar", 9))
		mandelbar(vars);
	if (!ft_strncmp(vars -> fract_ol, "mandelbrot", 10))
		mandelbrot(vars);
	if (!ft_strncmp(vars -> fract_ol, "julia", 5))
		julia(vars);
	return (0);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int	mouse_press_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
	{
		vars -> zoom = -0.1;
		if (!ft_strncmp(vars -> fract_ol, "mandelbrot", 10))
			mandelbrot(vars);
		if (!ft_strncmp(vars -> fract_ol, "julia", 5))
			julia(vars);
		if (!ft_strncmp(vars -> fract_ol, "mandelbar", 9))
			mandelbar(vars);
	}
	if (button == 5)
	{
		vars -> zoom = 0.1;
		if (!ft_strncmp(vars -> fract_ol, "mandelbrot", 10))
			mandelbrot(vars);
		if (!ft_strncmp(vars -> fract_ol, "julia", 5))
			julia(vars);
		if (!ft_strncmp(vars -> fract_ol, "mandelbar", 9))
			mandelbar(vars);
	}
	return (0);
}

void	init_vars (t_vars *vars)
{
	vars -> height = 500;
	vars -> width = 500;
	vars -> min = init_complex(-2.0, -2.0);
	vars -> max.re = 2.0;
	vars -> max.im = vars -> min.im + (vars -> max.re - vars -> min.re) \
					* vars -> height / vars -> width;
	vars -> mlx = mlx_init();
	vars -> win = mlx_new_window(vars -> mlx, vars -> height, \
									vars -> width, "FRACT-OL");
	vars -> zoom = 0;
	vars -> x_bias = 0;
	vars -> y_bias = 0;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Укажи название фрактала: mandelbrot/julia/mandelbar\n");
		exit (1);
	}
	init_vars(&vars);
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		mandelbrot(&vars);
	else if (!ft_strncmp(argv[1], "julia", 5))
		mlx_hook(vars.win, 6, 0, julia_motion, &vars);
	else if (!ft_strncmp(argv[1], "mandelbar", 9))
		mandelbar(&vars);
	else
	{
		printf("Укажи название фрактала: mandelbrot/julia/mandelbar\n");
		exit (1);
	}
	mlx_hook(vars.win, 4, 0, mouse_press_hook, &vars);
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
