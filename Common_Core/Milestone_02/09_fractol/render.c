/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 23:09:11 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/04 19:40:45 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0x000000);
	return (iter * 0xFF0000 / MAX_ITER);
}

static int	mandelbrot_iter(double re, double im)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		iter;

	z_re = 0;
	z_im = 0;
	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < MAX_ITER)
	{
		tmp = z_re * z_re - z_im * z_im + re;
		z_im = 2 * z_re * z_im + im;
		z_re = tmp;
		iter++;
	}
	return (iter);
}

void	render_mandelbrot(t_fractol *f)
{
	int		x;
	int		y;
	double	re;
	double	im;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x % 2 == 0 && y % 2 == 0)
			{
				re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_x;
				im = (y - HEIGHT / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_y;
				my_pixel_put(f, x, y, get_color(mandelbrot_iter(re, im)));
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
