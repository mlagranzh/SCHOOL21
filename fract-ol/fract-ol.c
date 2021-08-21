#include "fract-ol.h"

int	close(int keycode)
{
    if (keycode == 53)
        exit(0);
}

t_complex init_complex(double re, double im)
{
    t_complex complex;
    
    complex.re = re;
    complex.im = im;
    return (complex);
}

void mandelbrot(void *mlx, void *win, int x0, int y0, t_vars *vars)
{
// 	mlx_clear_window (mlx, win);
//     int HEIGHT = 1000;
//     int WIDTH = 1000;
// 	int color;

//     t_complex factor;
//     t_complex c;
//     t_complex z;
//     vars -> min.re +=  vars -> zoom;
// 	vars -> min.im +=  vars -> zoom;
//     vars -> max.re -=  vars -> zoom;
// 	vars -> max.im -=  vars -> zoom;
//     factor = init_complex((vars -> max.re - vars -> min.re) / (WIDTH - 1) , (vars -> max.im - vars -> min.im) / (HEIGHT - 1));

// 	void *vars -> image = mlx_new_vars -> image(mlx, 1000, 1000);
// int pixel_bits;
// int line_bytes;
// int endian;
// char *vars -> buffer = mlx_get_data_addr(vars -> image, &pixel_bits, &line_bytes, &endian);

// color = 0xABCDEF;

// if (pixel_bits != 32)
//     color = mlx_get_color_value(mlx, color);

// 	for(int y = 0; y < HEIGHT; y++)
// 	{
// 		c.im = vars -> max.im - y * factor.im;
// 		for(int x = 0; x < WIDTH; x++)
// 		{
// 			c.re = vars -> min.re + x * factor.re;
// 			z = init_complex(c.re, c.im);
// 			int i = 0;
// 			while (i < 50 && sqrt(z.im*z.im + z.re*z.re) < 2.0)
// 			{
// 				z = init_complex(
// 					z.re * z.re - z.im * z.im + c.re,
// 					2.0 * z.re * z.im + c.im);
// 				i++;
// 			}
// 		if (sqrt(z.im*z.im + z.re*z.re) >= 2.0)
// 		{
// 			double t = (double)i / 50.0;
// 			int red = (int)((t)  * 255);
// 			int green = (int)((t * t) * 255);
// 			int blue = (int)((t * t * t) * 255);
// 			int color = create_color (0, red, green, blue);
//     		int pixel = (y * line_bytes) + (x * 4);

//     if (endian == 1)        // Most significant (Alpha) byte first
//     {
//         vars -> buffer[pixel + 0] = (color >> 24);
//         vars -> buffer[pixel + 1] = (color >> 16) & 0xFF;
//         vars -> buffer[pixel + 2] = (color >> 8) & 0xFF;
//         vars -> buffer[pixel + 3] = (color) & 0xFF;
//     }
//     else if (endian == 0)   // Least significant (Blue) byte first
//     {
//         vars -> buffer[pixel + 0] = (color) & 0xFF;
//         vars -> buffer[pixel + 1] = (color >> 8) & 0xFF;
//         vars -> buffer[pixel + 2] = (color >> 16) & 0xFF;
//         vars -> buffer[pixel + 3] = (color >> 24);
//     }
// 		}
// 	}
// 	}
// 	mlx_put_vars -> image_to_window(mlx, win, vars -> image, 0, 0);
//  	mlx_destroy_vars -> image(mlx, vars -> image);
}


int	create_color(int i, int x, int y, int line_bytes)
{
	double t = (double)i / 50.0;
	int red = (int)((t) * 255);
	int green = (int)((t * t + 2 * t) * 255);
	int blue = (int)((t * t * t) * 255);
	int color = 0 << 24 | red << 16 | green << 8 | blue;
	return (color);
}

void draw(void *mlx, void *win, int x0, int y0)
{
	int x;
	int y;

	y = 0;
}

void julia(t_vars *vars)
{
	t_image img;
	
	mlx_clear_window(vars -> mlx, vars -> win);
    vars -> min.re +=  vars -> zoom;
	vars -> min.im +=  vars -> zoom;
    vars -> max.re -=  vars -> zoom;
	vars -> max.im -=  vars -> zoom;
    vars -> factor = init_complex((vars -> max.re - vars -> min.re) / (vars -> width - 1) , \
							(vars -> max.im - vars -> min.im) / (vars -> height - 1));
	vars -> image = mlx_new_image(vars -> mlx, vars -> height, vars -> width);
	vars -> buffer = mlx_get_data_addr(vars -> image, &(img.pixel_bits), &(img.line_bytes), &(img.endian));
    t_complex k;
    t_complex z;
	t_complex c;
	int x;
	int y;
	int i;

	y = 0;
	while ((++y) < vars -> height)
	{
		c.im = vars -> max.im - y * vars -> factor.im;
		x = 0;
		while ((++x) < vars -> width)
		{
			c.re = vars -> min.re + x * vars -> factor.re;
			z = init_complex(c.re, c.im);
			i = 0;
			while ((i++) < 50 && sqrt(z.im*z.im + z.re*z.re) < 2.0)
				z = init_complex( pow(z.re, 2.0) - pow(z.im, 2.0) + vars->k.re,\
					2.0 * z.re * z.im + vars->k.im);
			if (sqrt(z.im * z.im + z.re * z.re) >= 2.0)
			{
				img.color = create_color(i, x, y, img.line_bytes);
				img.pixel = (y * img.line_bytes) + (x * 4);
				// vars -> buffer[pixel + 0] = (color) & 0xFF;
				vars -> buffer[img.pixel + 1] = (img.color >> 8) & 0xFF;
				vars -> buffer[img.pixel + 2] = (img.color >> 16) & 0xFF;
				vars -> buffer[img.pixel + 3] = (img.color >> 24);
			}
		}
	}
	mlx_put_image_to_window(vars -> mlx, vars -> win, vars -> image, 0, 0);
 	mlx_destroy_image (vars -> mlx, vars -> image);
}

int julia_motion(int x, int y, t_vars *vars)
{
	vars -> k = init_complex(
		4 * ((double)x / vars -> width - 0.5),
		4 * ((double)(vars -> height - y) / vars -> height - 0.5));
    julia(vars);
    vars -> zoom = 0;
    return (0);
}

int	mouse_press_hook(int button, int x, int y, t_vars *vars)
{
    if (button == 4)
    {
        vars -> zoom = -0.1;
        if (!ft_strncmp(vars -> fract_ol, "mandelbrot", 5))
		    mandelbrot(vars -> mlx, vars -> win, x, y, vars);
        if (!ft_strncmp(vars -> fract_ol, "julia", 5))
		    julia(vars);
    }
	if (button == 5)
	{
        vars -> zoom = 0.1;
        if (!ft_strncmp(vars -> fract_ol, "mandelbrot", 5))
		    mandelbrot(vars -> mlx, vars -> win, x, y, vars);
        if (!ft_strncmp(vars -> fract_ol, "julia", 5))
		     julia(vars);
	}
	return (0);
}


void init_vars (t_vars *vars)
{
	vars -> height = 1000;
	vars -> width = 1000;
    vars -> min = init_complex(-2.0, -2.0);
    vars -> max.re = 2.0;
    vars -> max.im = vars -> min.im + (vars -> max.re - vars -> min.re) * vars -> height/vars -> width;
	vars -> mlx = mlx_init();;
	vars -> win = mlx_new_window(vars -> mlx, vars -> height, vars -> width, "FRACT-OL");;
    vars -> zoom = 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Укажи название фрактала: mandelbrot или julia\n");
        return (1);
    }
	t_vars vars;
    init_vars(&vars);
    if (!ft_strncmp(argv[1], "mandelbrot", 10))
    {
        vars.fract_ol = "mandelbrot";
        mandelbrot(vars.mlx, vars.win, 0, 0, &vars);
	    mlx_hook(vars.win, 4, 0, mouse_press_hook, &vars);
    }
    else if (!ft_strncmp(argv[1], "julia", 5))
    {
        vars.fract_ol = "julia";
	    mlx_hook(vars.win, 6, 0, julia_motion, &vars);
        mlx_hook(vars.win, 4, 0, mouse_press_hook, &vars);
    }
    else
    {
        printf("Укажи название фрактала: mandelbrot или julia\n");
        exit (1);
    }
	mlx_hook(vars.win, 2, 0, close, &vars);
    mlx_loop(vars.mlx);
}
