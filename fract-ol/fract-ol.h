#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "Libft/libft.h"
typedef struct s_complex 
{
    double re;
    double im;
} t_complex;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_complex min;
	t_complex max;
	t_complex k;
    char *fract_ol;
    double zoom;
	int height;
	int width;
	t_complex factor;
	char *buffer;
	void *image;
}				t_vars;

typedef struct	s_image {
int color;
int pixel;
char *buffer;
void *image;
	int	pixel_bits;
	int line_bytes;
	int endian;
}				t_image;

#endif