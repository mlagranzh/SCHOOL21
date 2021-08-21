#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int	close(int keycode)
{
    if (keycode == 53)
        exit(0);
}

typedef struct s_complex 
{
    double re;
    double im;
} t_complex;

t_complex init_complex(double re, double im)
{
    t_complex complex;
    
    complex.re = re;
    complex.im = im;
    return (complex);
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_complex min;
	t_complex max;
	t_complex k;
}				t_vars;

void draw(void *mlx, void *win, int x0, int y0)
{
void *image = mlx_new_image(mlx, 1, 1);
int pixel_bits;
int line_bytes;
int endian;
char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

int color = 0xABCDEF;

if (pixel_bits != 32)
    color = mlx_get_color_value(mlx, color);

for(int y = 0; y < 1; ++y)
for(int x = 0; x < 1; ++x)
{
    int pixel = (y * line_bytes) + (x * 4);

    if (endian == 1)        // Most significant (Alpha) byte first
    {
        buffer[pixel + 0] = (color >> 24);
        buffer[pixel + 1] = (color >> 16) & 0xFF;
        buffer[pixel + 2] = (color >> 8) & 0xFF;
        buffer[pixel + 3] = (color) & 0xFF;
    }
    else if (endian == 0)   // Least significant (Blue) byte first
    {
        buffer[pixel + 0] = (color) & 0xFF;
        buffer[pixel + 1] = (color >> 8) & 0xFF;
        buffer[pixel + 2] = (color >> 16) & 0xFF;
        buffer[pixel + 3] = (color >> 24);
    }
}
mlx_put_image_to_window(mlx, win, image, x0, y0);
mlx_destroy_image(mlx, image);
}


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void mondelbrod(void *mlx, void *win, int x0, int y0, t_vars *vars)
{
	mlx_clear_window (mlx, win);
    int HEIGHT = 1000;
    int WIDTH = 1000;
	int color = create_trgb (0, 0, 0, 0);
	// 	for(int y = 0; y < HEIGHT; y++)
	// {
	// 	for(int x = 0; x < WIDTH; x++)
	// 		mlx_pixel_put(mlx, win, x, y,  color);
	// }

    t_complex factor;
    t_complex c;
    t_complex z;
    vars -> min.re +=  1 / 10.0;
	vars -> min.im +=  1 / 10.0;
    vars -> max.re -=  1 / 10.0;
	vars -> max.im -=  1 / 10.0;
    factor = init_complex((vars -> max.re - vars -> min.re) / (WIDTH - 1) , (vars -> max.im - vars -> min.im) / (HEIGHT - 1));

	void *image = mlx_new_image(mlx, 1000, 1000);
int pixel_bits;
int line_bytes;
int endian;
char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

color = 0xABCDEF;

if (pixel_bits != 32)
    color = mlx_get_color_value(mlx, color);

	for(int y = 0; y < HEIGHT; y++)
	{
		c.im = vars -> max.im - y * factor.im;
		for(int x = 0; x < WIDTH; x++)
		{
			c.re = vars -> min.re + x * factor.re;
			z = init_complex(c.re, c.im);
			int i = 0;
			while (i < 50 && sqrt(z.im*z.im + z.re*z.re) < 2.0)
			{
				z = init_complex(
					z.re * z.re - z.im * z.im + c.re,
					2.0 * z.re * z.im + c.im);
				i++;
			}
		if (sqrt(z.im*z.im + z.re*z.re) >= 2.0)
		{
			double t = (double)i / 50.0;
			int red = (int)((t)  * 255);
			int green = (int)((t * t) * 255);
			int blue = (int)((t * t * t) * 255);
			int color = create_trgb (0, red, green, blue);
    		int pixel = (y * line_bytes) + (x * 4);

    if (endian == 1)        // Most significant (Alpha) byte first
    {
        buffer[pixel + 0] = (color >> 24);
        buffer[pixel + 1] = (color >> 16) & 0xFF;
        buffer[pixel + 2] = (color >> 8) & 0xFF;
        buffer[pixel + 3] = (color) & 0xFF;
    }
    else if (endian == 0)   // Least significant (Blue) byte first
    {
        buffer[pixel + 0] = (color) & 0xFF;
        buffer[pixel + 1] = (color >> 8) & 0xFF;
        buffer[pixel + 2] = (color >> 16) & 0xFF;
        buffer[pixel + 3] = (color >> 24);
    }
		}
	}
	}
	mlx_put_image_to_window(mlx, win, image, 0, 0);
 	mlx_destroy_image(mlx, image);
}


void julia(void *mlx, void *win, int x0, int y0, t_vars *vars)
{
    int HEIGHT = 1000;
    int WIDTH = 1000;
		mlx_clear_window (mlx, win);
	 int color = create_trgb (0, 0, 0, 0);
	// 	for(int y = 0; y < HEIGHT; y++)
	// {
	// 	for(int x = 0; x < WIDTH; x++)
	// 		mlx_pixel_put(mlx, win, x, y,  color);
	// }

    t_complex factor;
    t_complex k;
    t_complex z;
	t_complex c;
    // vars -> min.re +=  x0 / 10000.0;
	// vars -> min.im +=  y0 / 10000.0;
    // vars -> max.re -=  x0 / 10000.0;
	// vars -> max.im +=  y0 / 10000.0;
    factor = init_complex((vars -> max.re - vars -> min.re) / (WIDTH - 1) , (vars -> max.im - vars -> min.im) / (HEIGHT - 1));
	// k = init_complex(-0.4, 0.6);
	void *image = mlx_new_image(mlx, 1000, 1000);
int pixel_bits;
int line_bytes;
int endian;
char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

color = 0xABCDEF;

if (pixel_bits != 32)
    color = mlx_get_color_value(mlx, color);

	for(int y = 0; y < HEIGHT; y++)
	{
		c.im = vars -> max.im - y * factor.im;
		for(int x = 0; x < WIDTH; x++)
		{
			c.re = vars -> min.re + x * factor.re;
			z = init_complex(c.re, c.im);
			int i = 0;
			while (i < 50 && sqrt(z.im*z.im + z.re*z.re) < 2.0)
			{
				z = init_complex(
					pow(z.re, 2.0) - pow(z.im, 2.0) + vars->k.re,
					2.0 * z.re * z.im + vars->k.im);
				i++;
			}
		if (sqrt(z.im*z.im + z.re*z.re) >= 2.0)
		{
			double t = (double)i / 50.0;
			int red = (int)((t)  * 255);
			int green = (int)((t * t + 2 * t) * 255);
			int blue = (int)((t * t * t) * 255);
			int color = create_trgb (0, red, green, blue);
    		int pixel = (y * line_bytes) + (x * 4);

    if (endian == 1)        // Most significant (Alpha) byte first
    {
        buffer[pixel + 0] = (color >> 24);
        buffer[pixel + 1] = (color >> 16) & 0xFF;
        buffer[pixel + 2] = (color >> 8) & 0xFF;
        buffer[pixel + 3] = (color) & 0xFF;
    }
    else if (endian == 0)   // Least significant (Blue) byte first
    {
        buffer[pixel + 0] = (color) & 0xFF;
        buffer[pixel + 1] = (color >> 8) & 0xFF;
        buffer[pixel + 2] = (color >> 16) & 0xFF;
        buffer[pixel + 3] = (color >> 24);
    }
		}
	}
	}
	mlx_put_image_to_window(mlx, win, image, 0, 0);
 	mlx_destroy_image(mlx, image);

}

int julia_motion(int x, int y, t_vars *vars)
{
	int WIDTH = 1000;
	int HEIGHT = 1000;
    vars->k = init_complex(
        4 * ((double)x / WIDTH - 0.5),
        4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
    julia(vars->mlx, vars->win, 0, 0, vars);
    return (0);
}

int				mouse_press_hook(int button, int x, int y, t_vars *vars)
{
	// printf("%d\n", button);
	printf("%d\n", x);
	printf("%d\n", y);
	mondelbrod(vars -> mlx, vars -> win, x, y, vars);

	if (button == 4 || button == 5)
	{
		exit(0);
	}
	return (0);
}

int				mouse_release_hook(int button, int x, int y, t_vars *vars)
{
	// mondelbrod(vars -> mlx, vars -> win, 0, 0);
	// if (button == 4 || button == 5)
	// {
	// 	exit(0);
	// }
	// return (0);
}

int main()
{
	t_vars vars;
    vars.min = init_complex(-2.0, -2.0);
    (vars.max).re = 2.0;
    (vars.max).im = (vars.min).im + ((vars.max).re - (vars.min).re) * 1000/1000;
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 1000, 1000, "FRACT-OL");
	vars.mlx = mlx;
	vars.win = win;
	mondelbrod(mlx, win, 0, 0, &vars);

	mlx_hook(win, 2, 0, close, &vars);
	mlx_hook(win, 4, 0, mouse_press_hook, &vars);
	// mlx_hook(win, 6, 0, julia_motion, &vars);

	// mlx_hook(win, 5, 0, mouse_release_hook, &vars);

    mlx_loop(mlx);
}
