/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:55:20 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/04 19:53:37 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(0);
	return (0);
}

int	debounce_scroll(void)
{
	static int	counter = 0;

	counter++;
	if (counter % 2 == 0)
		return (1);
	return (0);
}

int	key_handler(int keycode, t_fractol *f)
{
	double	move_amount;

	if (keycode == KEY_ESC)
		return (close_window(f));
	move_amount = 0.15 / f->zoom;
	if (keycode == KEY_UP)
		f->offset_y -= move_amount;
	else if (keycode == KEY_DOWN)
		f->offset_y += move_amount;
	else if (keycode == KEY_LEFT)
		f->offset_x -= move_amount;
	else if (keycode == KEY_RIGHT)
		f->offset_x += move_amount;
	else
		return (0);
	if (f->fractal == MANDELBROT)
		render_mandelbrot(f);
	else
		render_julia(f);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *f)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	if (!debounce_scroll())
		return (0);
	zoom_factor = 1.05;
	mouse_re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_x;
	mouse_im = (y - HEIGHT / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_y;
	if (button == 4)
		f->zoom *= zoom_factor;
	else if (button == 5)
		f->zoom /= zoom_factor;
	else
		return (0);
	f->offset_x = mouse_re - (x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom);
	f->offset_y = mouse_im - (y - HEIGHT / 2.0) * 4.0 / (WIDTH * f->zoom);
	if (f->fractal == MANDELBROT)
		render_mandelbrot(f);
	else
		render_julia(f);
	return (0);
}
