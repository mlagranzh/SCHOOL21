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

// t_complex init_complex(double re, double im)
// {
//     t_complex complex;
    
//     complex.re = re;
//     complex.im = im;
//     return (complex);
// }

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
		double max_im = -2.0 + (2.0 + 2.0) * 1000.0 / 1000.0;
		double factor_re = (2.0 + 2.0) / (1000.0 - 1.0);
		double factor_im = (max_im + 2.0) / (1000.0 - 1.0);

		
	for(int y = 0; y < 1000; ++y)
	{
		double c_im = max_im - y * factor_im;
	for(int x = 0; x < 1000; ++x)
	{
		double c_re = -2.0 + x * factor_re;
		double im = c_im;
		double re = c_re;
		int i = 0;
		while (i < 50 && sqrt(im*im + re*re) < 2)
		{
			re = re*re - im*im + c_re;
			im = 2*re*im + c_im;
			++i;
		}
		if (sqrt(im*im + re*re) >= 2)
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

	double max_im = -2.0 + (2.0 + 2.0) * 300.0 / 300.0;
	double factor_re = (2.0 + 2.0) / (300.0 - 1.0);
	double factor_im = (max_im + 2.0) / (300.0 - 1.0);
	
for(int y = 0; y < 300; ++y)
{
	double c_im = max_im - y * factor_im;
for(int x = 0; x < 300; ++x)
{
	double c_re = -2.0 + x * factor_re;
	double im = c_im;
	double re = c_re;
	int i = 0;
	while (i < 50 && sqrt(im*im + re*re) < 2)
	{
		re = re*re - im*im + c_re;
		im = 2*re*im + c_im;
		++i;
	}
	if (sqrt(im*im + re*re) >= 2)
	{
		draw(mlx, win, x, y);
	}
}
}
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
