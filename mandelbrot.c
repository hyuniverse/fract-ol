/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:42:07 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/08 22:44:45 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calc_madelbrot(int real, int imag)
{
	double x;
	double	y;
	int	iter;
	double c_re, c_im;
	double tmp;

	c_re = (real - (WIDTH / 2)) * 2.5 / (double)WIDTH - 0.7;
	c_im = (imag - (HEIGHT / 2)) * 2.5 / (double)HEIGHT;
	x = 0;
	y = 0;
	iter = 0;
	while (x*x + y*y < 4 && iter < 100)
	{
		tmp = x*x - y*y + c_re;
		y = 2*x*y + c_im;
		x = tmp;
		iter++;
	}
	return iter;
}

static void	draw_mandelbrot(t_data *image)
{
	int		i;
	int		j;
	long	color;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			color = calc_madelbrot(i, j);
			if (color < 100)
			{
				color = ((255 - color * 5) << 24) + 0x40E0D0;
				my_mlx_pixel_put(image, i, j, color);
			}
			j++;
		}
		i++;
	}
}

void	main_mandelbrot(void)
{
	t_vars	vars;
	t_data	image;

	initialize(&vars, &image);
	draw_mandelbrot(&image);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	//mlx_loop_hook(vars.mlx, draw, &vars)
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
}
