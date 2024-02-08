/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:01:03 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/08 21:48:24 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <string.h>
#include <stdio.h>

static int	calc_madelbrot(int real, int imag, t_fractol f)
{
	int			iter;
	double		tmp;
	t_complex	c;
	t_complex	z;

	c.real = (real - (WIDTH / 2)) * 2.5 * f.zoom / (double)WIDTH - 0.7;
	c.imag = ((HEIGHT / 2) - imag) * 2.5 * f.zoom / (double)HEIGHT;
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

static int	calc_julia(int real, int imag, t_fractol f)
{
	t_complex	z;
	int			iter;
	double		tmp;

	z.real = (real - f.min_x) * 5 * f.zoom / (double)WIDTH;
	z.imag = (f.min_y - imag) * 5 * f.zoom / (double)HEIGHT;
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
			{
				color = ((255 - color) << 24) + 0x40E0D0;
				my_mlx_pixel_put(&f, i, j, color);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
}

int	mouse_hook(int keycode, int x, int y, t_fractol *f)
{
	//int	zoom;
	//(void)x;
	//(void)y;
	f->x = x;
	f->y = y;
	if (keycode == SCROLL_UP)
	{
		f->zoom *= 0.5;
		f->min_x = f->x + (WIDTH / 2- f->x) * f->zoom - WIDTH / 2 * f->zoom;
		f->min_y = f->y + (HEIGHT / 2 - f->y) * f->zoom - HEIGHT / 2 * f->zoom;
	}
	else if (keycode == SCROLL_DOWN)
	{
		f->zoom *= 2.0;
		f->min_x = f->x + (WIDTH / 2- f->x) * f->zoom - WIDTH / 2 * f->zoom;
		f->min_y = f->y + (HEIGHT / 2 - f->y) * f->zoom - HEIGHT / 2 * f->zoom;
	}
	draw(*f);
	return (0);
}

void	render(t_fractol f)
{
	initialize(&f);
	draw(f);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, exit_hook, 0);
	mlx_loop(f.mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc == 2 && strncmp(argv[1], "mandel", 6) == 0)
	{
		f.type = 1;
		render(f);
		//main_mandelbrot();
	}
	else if (argc == 4 && strncmp(argv[1], "julia", 5) == 0)
	{
		f.type = 2;
		f.julia.real = atof(argv[2]);
		f.julia.imag = atof(argv[3]);
		render(f);
	}
	else
		print_man();
}