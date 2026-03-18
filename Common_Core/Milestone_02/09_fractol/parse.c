/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:03:10 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/04 20:27:54 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	print_usage(char *name)
{
	write(1, "Usage: ", 7);
	write(1, name, ft_strlen(name));
	write(1, " mandelbrot | julia <re> <im>\n", 30);
	return (0);
}

static int	parse_julia(t_fractol *f, int argc, char **argv)
{
	if (argc != 4)
	{
		write(1, "Usage: julia <re> <im>\n", 23);
		write(1, "Example: julia -0.821 -0.2121\n", 30);
		return (0);
	}
	if (!ft_isfloat(argv[2]) || !ft_isfloat(argv[3]))
	{
		write(1, "Usage: julia <re> <im>\n", 23);
		write(1, "Example: julia -0.821 -0.2121\n", 30);
		return (0);
	}
	f->fractal = JULIA;
	f->julia_re = ft_atof(argv[2]);
	f->julia_im = ft_atof(argv[3]);
	return (1);
}

int	parse_args(t_fractol *f, int argc, char **argv)
{
	if (argc < 2)
		return (print_usage(argv[0]));
	if (!ft_strcmp(argv[1], "mandelbrot"))
		f->fractal = MANDELBROT;
	else if (!ft_strcmp(argv[1], "julia"))
		return (parse_julia(f, argc, argv));
	else
	{
		write(1, "Invalid fractal type\n", 21);
		return (0);
	}
	return (1);
}
