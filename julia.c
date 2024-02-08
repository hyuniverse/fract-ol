/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:42:03 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/08 22:44:47 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calc_julia(int real, int imag, double c_re, double c_im, double zoom)
{
	double	x;
	double	y;
	int		iter;
	double	tmp;

	x = (real - (WIDTH / 2)) * 5 * zoom/ (double)WIDTH;
	y = (imag - (HEIGHT / 2)) * 5 * zoom/ (double)HEIGHT;
	iter = 0;
	while (x * x + y * y < 4 && iter < 1000)
	{
		tmp = x * x - y * y + c_re;
		y = 2 * x * y + c_im;
		x = tmp;
		iter++;
	}
	return (iter);
}

static void	draw_julia(t_data *image, double real, double imag, double zoom)
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
			color = calc_julia(i, j, real, imag, zoom);
			if (color < 1000)
			{
				color = ((255 - color * 2) << 24) + 0x40E0D0;
				my_mlx_pixel_put(image, i, j, color);
			}
			j++;
		}
		i++;
	}
}

void	main_julia(double real, double imag)
{
	t_vars	vars;
	t_data	image;

	initialize(&vars, &image);
	draw_julia(&image, real, imag, 1);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
}
