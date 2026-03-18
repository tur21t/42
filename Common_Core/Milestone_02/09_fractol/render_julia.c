/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:41:31 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/04 19:48:24 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0x000000);
	return (iter * 0xFF0000 / MAX_ITER);
}

static int	julia_iter(double z_re, double z_im, double re, double im)
{
	double	tmp;
	int		iter;

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

void	render_julia(t_fractol *f)
{
	int		x;
	int		y;
	double	z_re;
	double	z_im;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z_re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_x;
			z_im = (y - HEIGHT / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_y;
			my_pixel_put(
				f, x, y,
				get_color(julia_iter(z_re, z_im, f->julia_re, f->julia_im))
				);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
