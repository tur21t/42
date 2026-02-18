/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:15:45 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/04 16:12:07 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define WIDTH 1080
# define HEIGHT 1080
# define MAX_ITER 100

typedef enum e_type
{
	MANDELBROT,
	JULIA
}	t_type;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	double	zoom;
	double	offset_x;
	double	offset_y;

	t_type	fractal;
	double	julia_re;
	double	julia_im;
}	t_fractol;

int		close_window(t_fractol *f);
int		key_handler(int keycode, t_fractol *f);
int		mouse_handler(int button, int x, int y, t_fractol *f);

void	my_pixel_put(t_fractol *f, int x, int y, int color);
void	render_mandelbrot(t_fractol *f);
void	render_julia(t_fractol *f);
int		parse_args(t_fractol *f, int argc, char **argv);

int		ft_isfloat(char *s);
size_t	ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
double	ft_atof(char *s);

#endif
