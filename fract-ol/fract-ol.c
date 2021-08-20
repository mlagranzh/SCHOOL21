#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

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

void mondelbrod(void *mlx, void *win)
{
    int HEIGHT = 1000;
    int WIDTH = 1000;
    t_complex min;
    t_complex max;
    t_complex factor;
    t_complex c;
    t_complex z;
    min = init_complex(-2.0, -2.0);
    max.re = 2.0;
    max.im = min.im + (max.re - min.re) * HEIGHT/WIDTH;
    factor = init_complex((max.re - min.re) / (WIDTH - 1) , (max.im - min.im) / (HEIGHT - 1));

	for(int y = 0; y < HEIGHT; y++)
	{
		c.im = max.im - y * factor.im;
		for(int x = 0; x < WIDTH; x++)
		{
			c.re = min.re + x * factor.re;
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
			int red = (int)(9 * (1 - t) * pow(t, 3) * 255);
			int green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
			int blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
			int color = create_trgb (t, red, green, blue);
			mlx_pixel_put(mlx, win, x, y,  color);
		}
	}
	}
}

void julia(void *mlx, void *win)
{

}

int main()
{
	t_vars vars;
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 1000, 1000, "FRACT-OL");
	mondelbrod(mlx, win);

	mlx_hook(win, 2, 1L<<0, close, &vars);
	mlx_mouse_hook(win, close, &vars);
    mlx_loop(mlx);
}
