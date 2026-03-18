/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:15:27 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/04 20:33:10 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

int	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (0);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract'ol");
	if (!f->win)
	{
		free(f->mlx);
		return (0);
	}
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (!parse_args(&f, argc, argv))
		return (1);
	if (!init_fractol(&f))
		return (1);
	if (f.fractal == MANDELBROT)
		render_mandelbrot(&f);
	else
		render_julia(&f);
	mlx_key_hook(f.win, key_handler, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_mouse_hook(f.win, mouse_handler, &f);
	mlx_loop(f.mlx);
	return (0);
}
