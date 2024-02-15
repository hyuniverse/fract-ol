/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:21:29 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/15 20:22:36 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	calc_madelbrot(int x, int y, t_fractol f)
{
	int			iter;
	long double	tmp;
	t_complex	c;
	t_complex	z;

	c.real = ((x - f.px) / (long double)WIDTH * 4.0) / f.zoom + f.cx;
	c.imag = (f.py - y) / (long double)HEIGHT * 4.0 / f.zoom + f.cy;
	z.real = 0;
	z.imag = 0;
	iter = 0;
	while (z.real * z.real + z.imag * z.imag < 4 && iter < 1000)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
		iter++;
	}
	return (iter * 5);
}

static int	calc_julia(int x, int y, t_fractol f)
{
	t_complex	z;
	int			iter;
	long double	tmp;

	z.real = (x - f.px) / (long double)WIDTH * 4 / f.zoom + f.cx;
	z.imag = (f.py - y) / (long double)HEIGHT * 4 / f.zoom + f.cy;
	iter = 0;
	while (z.real * z.real + z.imag * z.imag < 4 && iter < 1000)
	{
		tmp = z.real * z.real - z.imag * z.imag + f.julia.real;
		z.imag = 2 * z.real * z.imag + f.julia.imag;
		z.real = tmp;
		iter++;
	}
	return (iter * 2);
}

void	draw(t_fractol f)
{
	int		i;
	int		j;
	long	color;

	mlx_clear_window(f.mlx, f.win);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (f.type == 1)
				color = calc_madelbrot(i, j, f);
			else
				color = calc_julia(i, j, f);
			if (color < 1000)
				color = ((255 - color) << 24) + 0x40E0D0;
			else
				color = 0x000000;
			my_mlx_pixel_put(&f, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
}
